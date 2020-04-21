FROM ubuntu

RUN apt-get update && apt-get install -y git g++ make wget cmake build-essential gdb

