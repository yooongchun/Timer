本文介绍如何在`Windows10`下安装`Qt`

---

##安装QT

首先要明确一点，`Qt`有支持`msvc`和支持`mingw`的两个版本，首先下载主安装程序：http://download.qt.io/archive/qt/，博主下载时(2019.03.01)最新版本是`5.12`，安装包名字是`qt-opensource-windows-x86-5.12.1.exe` ，下载下来之后点击安装，当选择安装选项时，博主这里因为要用`vs`来进行开发，故而选择`msvc`版本![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/Qt_install.png)

如果要选择`Mingw`版本，则选择`Qt12.1`目录下的`MSVC2017/64-bit`安装选项即可，而不必选择`Tools`目录下的文件。

选择好后等待安装，需要很长时间，安装好后开始配置`VS`

## 配置VS2017

在`VS`中开发`Qt`项目需要安装一个插件，依次选择`Tools`--->`Extensions and updates`，选中`Online`，在搜索框中搜索`Qt Visual Studio Tools` 并安装，重启`VS`安装插件，安装好后配置插件

首先打开`Qt VS Tools`-->`Qt Options`，点击添加，选中你的`Qt`安装目录下的`msvc`路径，然后确定

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/Qtsettings.png)

**新建测试工程** 

此时选择新建-->工程-->Qt工程即可建立Qt工程

![](https://yooongchun-blog.oss-cn-hangzhou.aliyuncs.com/Qt_timer/Qtproject.png)

关于在`VS`中开发`Qt`项目可阅读博主另外的文章！