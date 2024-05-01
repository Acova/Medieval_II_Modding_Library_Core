FROM mcr.microsoft.com/devcontainers/cpp:ubuntu

RUN sudo apt-get update -y
RUN sudo apt-get upgrade -y
RUN sudo apt install sqlite3 -y

COPY . /opt/projects/medieval-ii-modding-core-library

WORKDIR /opt/projects/medieval-ii-modding-core-library