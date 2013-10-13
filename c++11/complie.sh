#!/bin/bash

complie()
{
    g++ -Wall -g -std=c++0x $1 -o ${$1%.cpp}
}


