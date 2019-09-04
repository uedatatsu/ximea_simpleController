# ximea_simpleController
Simple controller for ximea camera

## Environment
### Software
- Windows 10
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

### 3. Change WIN32 → _WIN32 in "xiApi.h"
![be](https://user-images.githubusercontent.com/28892387/60168126-53ee5280-983f-11e9-927f-8ea26911c4ee.PNG)→→
![af](https://user-images.githubusercontent.com/28892387/60168164-56e94300-983f-11e9-9605-9159c50935c1.PNG)

### 4. Add system environment variable
System properties → environment variable → system environment variable → Path

add
```rb
C:\XIMEA\API\x64
```

### 5. Reboot your PC



