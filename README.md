# Cabify Challenge

- Comunication protocol: REST over http
- Server: Developed in C++17
    - Listener in localhost:9000
    - Used MVC architecture
        - Model: Memory (not database)
        - View: Rest server
        - Controller: One per each action (create basket, add product, get amount)
    - Steps to compile and build (from root source dir):
        - mkdir build
        - cd build
        - cmake ..
        - make
    - After these steps a bin directory (at root level) will be created with cabify-store-server binary file
    - Requeriments (development environment):
        - Threads library installed
        - gcc (version 7)
        - cmake (version 3.11)
        - Ubuntu 18.04
    - Example (from bin dir):
        <p>./cabify-store-server</p>

- Client: Developed in Go (version 1.6.2)
    - Arguments passed to program (list of products to add to the basket)
    - Client connects to localhost:9000
    - Only on file: client.go
    - Steps to build (from root source dir):
        - go build -o ./bin/cabify-store-client client/client.go
    - After these steps a bin directory (at root level) will be created with cabify-store-client binary file
    - Requeriments (development environment):        
        - golang-go package installed        
        - Ubuntu 18.04
    - Example (from bin dir):
        <p>./cabify-store-client VOUCHER VOUCHER<br>Ouput:<br>Items:VOUCHER, VOUCHER<br>Total: 10</p>

- Additional info:
    - REST server tested with Postman application

- Nexts steps (improvements)
    - Unit tests (I prefer TDD but due to time constraints I could not do it)
    - Functional tests (I would like to use a BDD tool, possibly Cucumber)
    - Configure ip and port (config file or command line arguments)
    - Microservice development (client and server in different containers using docker)
    - (...)
