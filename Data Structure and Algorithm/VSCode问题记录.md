# 记录使用时出现过的各种问题和解决方法

## 1、代码默认UTF_8编码，在终端运行时中文显示乱码

原因：VSCode终端借用了电脑的PowerShell 和Cmd,其默认编码格式为GBK

解决：在全局设置（setting.json）中加入一段代码（terminal开头），将终端编码格式改为"chcp 65001"，即UTF_8编码

### 注意：每次加入这段代码后，需要重新打开项目让新配置生效

## 2、遇到GBK格式的带中文文件，想要将其转为UTF_8编码，直接转会乱码

原因：直接转格式并没有改变底层编码集，仅仅只是用另一种编码方式对底层编码集进行译码

解决:用插件GBK to UTF8 for vscode，根据文件的内容，用目标格式重新编写文件，改变了底层编码

## 3、安装Clangd插件及Github上的支持包并添加bin路径到系统环境变量，失能原来的C/C++后，正确代码报错

原因：未知

解决：该插件适用于大型项目，目前阶段无关紧要，插件及支持包全部删除

## 4、VSCode无法调试程序

原因：文件名不能是中文

解决：每次调试都把主文件代码复制到Debug.cpp

## 5、VSCode无法运行STM32项目

原因：全局设置终端中文不乱码的命令

解决：删除这段命令

### 注意：打开其他纯软件项目前需要重新加上这段代码
