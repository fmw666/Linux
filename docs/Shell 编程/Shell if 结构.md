## 「 Shell if 结构 」

<div align="right">
    <a href="https://github.com/fmw666/Linux#-目录导航">返回目录导航 ↩</a>
</div>

### 💬 格式

```bash
if 条件测试
    then
    条件为真时的命令
    else
    条件为假时的命令
fi
```

### 💬 举例1

```bash
#!/bin/bash
#命令执行后返回值为0，报告命令执行成功
#否则报告出错
true
if (($?==0))
then
    echo "command was successful."
else
    echo "An error was encountered"
fi
```

### 💬 举例2

```bash
#!/bin/bash
read answer
if (($answer==0))
then
    echo "command was successful."
else
    if (($answer==-1))
    then
        echo "An error -1 was encountered."
    else
        echo "An other error was encountered."
    fi
fi
```

<div align="center">
    - End -
</div>