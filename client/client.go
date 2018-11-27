package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"bytes"
	"encoding/json"
	"strconv"
)

func main() {
	body := []byte("")

	urlbase := "http://localhost:9000/"
	ulrpostbasket := urlbase + "basket/"

	response, err := http.Post(ulrpostbasket, "application/json", bytes.NewBuffer(body))
	if err != nil {
		fmt.Print(err.Error())
		os.Exit(1)
	}
	responseData, err := ioutil.ReadAll(response.Body)
	if err != nil {
		log.Fatal(err)
	}
	var basketdata map[string]interface{}
	err = json.Unmarshal(responseData, &basketdata)
	
	if err != nil {
		log.Fatal(err)
  }
	id := int(basketdata["id"].(float64))
  
	fmt.Print("Items:")
	for i, arg := range os.Args[1:] {
		if i > 0 {
			fmt.Print(", ")
		}
		fmt.Print(arg)
		ulrpostproduct := ulrpostbasket + strconv.Itoa(id) + "/product?code="
		ulrpostproductvoucher := ulrpostproduct + arg

		response, err = http.Post(ulrpostproductvoucher, "application/json", bytes.NewBuffer(body))
		if err != nil {
			fmt.Print(err.Error())
			os.Exit(1)
		}
		responseData, err = ioutil.ReadAll(response.Body)
		if err != nil {
			log.Fatal(err)
		}
	}
	fmt.Println();

	ulrgetamount := ulrpostbasket + strconv.Itoa(id) + "/amount"
	response, err = http.Get(ulrgetamount)
	if err != nil {
		fmt.Print(err.Error())
		os.Exit(1)
	}
	responseData, err = ioutil.ReadAll(response.Body)
	if err != nil {
		log.Fatal(err)
	}
	var totaldata map[string]interface{}
	err = json.Unmarshal(responseData, &totaldata)
	
	if err != nil {
		log.Fatal(err)
  }
	total := totaldata["total"].(float64)
	fmt.Println("Total:", total)	
}
