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
```rb
  C:\OpenCV\4.0.1\include
  C:\XIMEA\API
```

Additional library directory in linker
```rb
  C:\OpenCV\4.0.1\x64\vc15\lib
  C:\XIMEA\API\x64
```

Additional dependency file in linker
```rb
  opencv_world401d.lib
  xiapi64.lib
```

### 3. WIN32 → _WIN32
in "xiApi.h", change ""
