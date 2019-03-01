Qt项目计时器

---

## 应用介绍

本文介绍一个在`Windows10` 平台下使用`Virsual Studio2017`+`Qt5.12.1`开发的项目计时器，应用界面如下

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/timer.png)

 应用界面主要包括：

- 项目名称
- 工作备注
- 作者

以及相应的`按键`和`计时器`及`日志显示`和`导出`。

## 安装Qt+VS

首先需要安装必须的`Qt`和`VS`，安装可参考博主的这篇文章：http://www.yooongchun.cn/detail/26

## 代码开发

代码开发的思路是使用`Qt设计师`生成`ui`文件，然后使用`Qt`自带的命令行工具生成C++的头文件，生成命令如下：

```powershell
uic your_ui_file.ui -o your_ui_cpp_file.h
```

生成之后即可通过在VS项目中引入头文件来使用，我的工程目录如下

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/vsroject.png)

接下来撰写逻辑代码，这里要用到一个`boost` 库用来进行对象序列化操作

## 安装boost库

可到这里下载：https://www.boost.org/users/history/version_1_69_0.html

博主下载时(2019.03.01)时最新版本是1-69-0，博主安装参考的是这篇文章：https://blog.csdn.net/fsac213330/article/details/52748223

这里说明一点，本文的程序需要用到编译安装的`boost`库。

最后打包生成`exe`文件，这里打包需要用到一个插件

## 安装打包插件

仍旧是在插件下载位置，搜索下载`Microsoft Visual Studio Installer Project`，下载安装好之后重启VS即可。

## 逻辑代码

代码较多，详情可去博主的`Github`下载：



## 打包代码

程序撰写完毕并且无错误后需要进行代码打包，这里博主的程序使用`Release 64bit`模式生成。

首先选择文件-->添加-->工程，然后按如下图选择工程

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/installer.png)

接下来配置工程

__STEP 1：添加主输出__

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/step1.png)

__

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/step0.png)

__STEP 2：添加程序图标文件(可选)__

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/step2.png)

__STEP 3：添加项目文件夹__

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/step3.png)



__STEP 4：生成安装器__

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/step4.png)



生成的文件在工程的`Setup`目录的`Release`目录下。

## 添加动态链接文件

上述步骤生成的程序安装后运行会出现如下错误：

```shell
this application failed to start because it could not find or load the qt platform plugin 'windows' in ''
```

原因是缺少运行程序必须的动态链接库。为了解决这个问题，首先，需要知道程序依赖哪些`dll`库，使用`VS`自带的命令行工具可查看，打开命令行工具，切换到`exe`程序所在目录，执行以下命令

```shell
dumpbin /imports your_file.exe >out.txt
```

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/vs_cmd.png)

执行完之后会生成一个`out.txt`的文件，里面有依赖的`dll`文件，在系统中搜索这些文件名，把这些文件在统一复制到一个文件夹内，以备后用。

## 下载安装打包工具

接下来要把这些链接库打包进`your_file.exe`中，当然，你要是不想打包，将上述文件夹路径添加到系统路径也可以运行。打包需要安装一个软件，首先下载`Inno Setup`软件：http://www.jrsoftware.org/isdl.php

安装好之后进行打包

创建新脚本：

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/setup1.png)

填写程序名称、版本号、发行者、网站等信息

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/setup.png)

浏览到`exe`文件位置选择`exe`，并天机刚才准备的`dll`文件		

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/setup2.png)

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/setup3.png)

填写生成的安装包输出位置及相应信息

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/setup4.png)

没有提到的选择默认信息即可，最后执行脚本生成文件。

生成文件进行安装，安装完毕启动程序：

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/timer.png)

