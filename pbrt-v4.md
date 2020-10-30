# PBRT-v4 related resources

https://pharr.org/matt/blog/2020/08/19/pbrt-v4-released.html

https://pharr.org/matt/blog/2019/10/23/profiling-the-pbrt-build.html

https://www.youtube.com/watch?v=prZJ8FBG9BI&t=6386s

https://www.youtube.com/watch?v=AXuk7bmhZ2g

 

## Imprvoments
  - GPU based rendering (Optix 7.1 and Cuda 11)
  - preview rendering process via Tev image viewer.

 

## Code structure

![image-20200822002016771](C:/Users/gaoduan/AppData/Roaming/Typora/typora-user-images/image-20200822002016771.png)

Ext/

Pbrt/

​    Bsdf.h(cpp)

​    Camera.h(cpp)

​    … 
  >  All material related codes are collected into a single file `bsdf.cpp`;
  > All camera related codes are also collected into a single file `camera.cpp`;
  > ...


​    Base/

![image-20200822002047537](C:/Users/gaoduan/AppData/Roaming/Typora/typora-user-images/image-20200822002047537.png)

> Virutal function ==> dynamic dispatch. This is the key techinique to support both GPU and CPU the same time.
>
> In `base` folder, there are header files of base class of each component (e.g. shape, light, camera, material)
> The role of these header files:
> 1. Define their handle 
>    e.g. shape.h define `shapeHandle`. All these handles are inherited from Tagged pointer which is implemented through C++ template programming and is the based of dynamic dispatch.
>     
>    We need to register all specific types in the statement of handle tyep.
>    e.g. shapeHandle: public TaggedPointer<Triangle, Curve, Sphere, Cylinder, Disk>
>         After defining the above handle, we can do dynamic dispatch.
>
> 2. Define the interace of each class
>   
>    e.g. The sub-class of shape needs to implement the following interfaces (identical to PBRT-v3):
>
>    ![image-20200822004523584](C:/Users/gaoduan/AppData/Roaming/Typora/typora-user-images/image-20200822004523584.png)
>
>    



​    Cpu/

​    Gpu/

​    Util/ (low-level codes)

![image-20200822002034966](C:/Users/gaoduan/AppData/Roaming/Typora/typora-user-images/image-20200822002034966.png)

> 1. including math library (e.g. vector, matrix) 
> 2. data structure (e.g. container)



## Build 

Dependencies:
- Cuda 11 (nvidia driver > 450)
- Optix 7.1

Step by step:

1. Install nvidia driver (ubuntu 20.04)

```bash
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt update
sudo apt install ubuntu-drivers-common
ubuntu-drivers devices
sudo apt install nvidia-driver-450
sudo reboot
```



2. Install CudaToolKit 11.0

```bash
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2004/x86_64/cuda-ubuntu2004.pin
sudo mv cuda-ubuntu2004.pin /etc/apt/preferences.d/cuda-repository-pin-600
wget https://developer.download.nvidia.com/compute/cuda/11.0.3/local_installers/cuda-repo-ubuntu2004-11-0-local_11.0.3-450.51.06-1_amd64.deb
sudo dpkg -i cuda-repo-ubuntu2004-11-0-local_11.0.3-450.51.06-1_amd64.deb
sudo apt-key add /var/cuda-repo-ubuntu2004-11-0-local/7fa2af80.pub
sudo apt-get update
sudo apt-get -y install cuda

```

3. Install Optix-7.1

```bash

sudo apt install xorg-dev libglu1-mesa-dev

# install gcc-4.8
sudo gedit /etc/apt/sources.list
# append `deb http://dk.archive.ubuntu.com/ubuntu/ xenial main
# deb http://dk.archive.ubuntu.com/ubuntu/ xenial universe`
sudo apt update && sudo apt install g++-4.8 gcc-4.8

# Download Optix-7.1 from https://developer.nvidia.com/designworks/optix/download

# build Optix
cd SDK && mkdir build && cd build
cmake -D CUDA_NVCC_FLAGS="-ccbin gcc-4.8" ..
make

```

4. Build PBRT-v4

```bash
cd pbrt-v4 && mkdir build && cd build

cmake -DPBRT_OPTIX7_PATH=~/Downloads/NVIDIA-OptiX-SDK-7.1.0-linux64-x86_64 ..

make 

sudo make install # install binary file into /usr/local/bin
```


# Other Optix path tracer related resources 

-  https://github.com/knightcrawler25/Optix-PathTracer 
-  PathTracer in the Optix 7.0 SDK
-  https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda/ 
-  https://github.com/ingowald/RTOW-OptiX 
-  https://developer.nvidia.com/blog/how-to-get-started-with-optix-7/ 