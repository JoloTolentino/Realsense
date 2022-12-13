
#base image that has c++ and opencv installed
FROM ubuntu:16.04


RUN apt-get update && apt-get install -y \
    build- essential \ 
    libopencv-dev \
    libopencv-core-dev \
    libopencv-highui-dev 


COPY . /app
WORKDIR /app

RUN make
CMD [ "./main" ]

