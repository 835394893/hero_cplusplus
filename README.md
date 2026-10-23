# 数据结构 C++ 练习

用 C++ 手写基础数据结构，并用它们完成一些入门练习题。

## 目录结构

```
.
├── 顺序表/
│   ├── 手写顺序表模板.cpp   # 顺序表的完整实现与演示
│   ├── vector.cpp           # STL vector 的基本用法
│   ├── 1.求奇数乘积.cpp
│   ├── 2.数值统计.cpp
│   ├── 3.评委打分.cpp
│   └── 4.猜数字.cpp
├── 链表/
│   └── 手写链表.cpp         # 单链表实现（进行中）
└── .vscode/                 # VS Code + MinGW 编译调试配置
```

## 顺序表

### 手写顺序表模板

`SequentialList` 结构体包含元素数组 `elements`、当前长度 `size` 和容量 `capacity`。容量不足时自动扩容为原来的 2 倍。

| 函数 | 作用 |
|---|---|
| `initializeList(list, capacity)` | 按给定容量初始化 |
| `destroyList(list)` | 释放内存 |
| `size(list)` / `isEmpty(list)` | 获取长度 / 判断是否为空 |
| `insert(list, index, element)` | 在指定下标插入元素 |
| `deleteElement(list, index)` | 删除指定下标的元素 |
| `findElement(list, element)` | 查找元素，返回下标，找不到返回 `-1` |
| `getElement(list, index)` | 获取指定下标的元素 |
| `updataElement(list, index, value)` | 修改指定下标的元素 |

下标越界时抛出 `std::invalid_argument`。元素类型通过 `#define eleType` 修改。

### vector.cpp

演示 `std::vector` 的初始化、遍历、`size()` 和 `push_back()`。

### 练习题

练习 1 到 3 都使用上面手写的顺序表来存数据。

| 题目 | 输入 | 输出 |
|---|---|---|
| 1. 求奇数乘积 | 多组数据，每组先给 `n`，再给 `n` 个整数 | 其中所有奇数的乘积 |
| 2. 数值统计 | 多组数据，每组先给 `n`（为 0 时结束），再给 `n` 个实数 | 负数、零、正数的个数 |
| 3. 评委打分 | 多组数据，每组先给 `n`，再给 `n` 个分数 | 去掉一个最高分和一个最低分后的平均分，保留两位小数 |
| 4. 猜数字 | 多组数据，每组 3 个猜测值和 3 个答案 | 猜对的次数 |

## 链表

`手写链表.cpp` 实现了带头指针的单链表 `LinkedList`，节点类型为 `ListNode`。

- 已实现：析构函数、`insert(i, value)`、`remove(i)`
- 待实现：`find`、`get`、`update`、`print`，以及测试用的 `main`

## 编译运行

任意一个 `.cpp` 文件都可以单独编译：

```bash
g++ "顺序表/1.求奇数乘积.cpp" -o odd_product
./odd_product
```

在 VS Code 中，`.vscode/tasks.json` 已配置好 MinGW 的 `g++`（路径为 `D:/mingw64/bin/g++.exe`），打开文件后按 `Ctrl+Shift+B` 即可编译当前文件。如果你的 MinGW 装在别的位置，需要修改该路径。
