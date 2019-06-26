# ximea_simpleController
Simple controller for ximea camera

## Environment
### Software
- Visual studio 2017
- OpenCV 4.0.1

### Hardware
- XiQ MQ013CG-ON (Camera)

## Setup
### 1. Download XIMEA Windows Software Package
from https://www.ximea.com/support/wiki/apis/XIMEA_Windows_Software_Package

### 2. Change visual studio property
Additional include directory in C/C++
  C:\OpenCV\4.0.1\include
  C:\XIMEA\API

### 2. WIN32 → _WIN32
in "xiApi.h", change ""
