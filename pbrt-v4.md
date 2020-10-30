Pbrt-v4相关资源介绍：

https://pharr.org/matt/blog/2020/08/19/pbrt-v4-released.html

https://pharr.org/matt/blog/2019/10/23/profiling-the-pbrt-build.html

https://www.youtube.com/watch?v=prZJ8FBG9BI&t=6386s

https://www.youtube.com/watch?v=AXuk7bmhZ2g

 

## 功能改进

 可以连接tev图片浏览器实时预览渲染结果；

 

## 代码结构

![image-20200822002016771](C:/Users/gaoduan/AppData/Roaming/Typora/typora-user-images/image-20200822002016771.png)

Ext/

Pbrt/

​    Bsdf.h(cpp)

​    Camera.h(cpp)

​    … 
  >  将所有材质collect到一个文件bsdf.cpp，所有camera也collect到一个文件camera.cpp



​    Base/

![image-20200822002047537](C:/Users/gaoduan/AppData/Roaming/Typora/typora-user-images/image-20200822002047537.png)

> 从虚函数转向动态 dispatch，也是实现GPU支持的支撑技术。
>
> base 中有每个基本组件的基类的.h文件，例如shape、light、camera、material等，这些头文件主要完成两件事情：
>
> 1. 定义其handle类型
>
>    例如shape，定义shapehandle。这些handle继承自tagged pointer，tagged pointer是模板机制实现，给予动态dispatch的能力。
>
>    先不管具体的tagged pointer的实现问题，在声明handle的时候需要注册所有具体的类型，例如shapehandle : public TaggedPointer<Triangle, Curve, Sphere, Cylinder, Disk>，这样定义之后就有动态分派的能力了。
>
> 2. 定义每个类的接口
>
>    例如shape，需要实现以下接口（和pbrt-v3的功能一致）：
>
>    ![image-20200822004523584](C:/Users/gaoduan/AppData/Roaming/Typora/typora-user-images/image-20200822004523584.png)
>
>    



​    Cpu/

​    Gpu/

​    Util/ (底层的代码)

![image-20200822002034966](C:/Users/gaoduan/AppData/Roaming/Typora/typora-user-images/image-20200822002034966.png)

> 1. 包含vector、matrix等math相关的代码
> 2. container等数据结构



 build 

- need c++ 17, optix 7.1, cuda 11
- need RTX 

​    

# 其他Optix path tracer相关的材料

-  https://github.com/knightcrawler25/Optix-PathTracer 

- Optix 7.0 SDK中包含path tracer实现以及其他内容。
-  https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda/ 
-  https://github.com/ingowald/RTOW-OptiX 
-  https://developer.nvidia.com/blog/how-to-get-started-with-optix-7/ 