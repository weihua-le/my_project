# `git push` 被拒绝的原因是 **远程仓库的 `main` 分支比本地 `main` 更新**
你的 `git push` 被拒绝的原因是 **远程仓库的 `main` 分支比本地 `main` 更新**，Git 不允许非快进（non-fast-forward）推送，以防止丢失远程的更新。  

---

## **解决方案**
### ✅ **方法 1：先拉取远程代码，然后推送（推荐）**
```sh
git pull --rebase origin main
git push origin main
```
- `git pull --rebase origin main`：拉取远程 `main` 分支的最新代码，并把你的本地提交重新应用到最新的远程代码之上。
- `git push origin main`：推送你的代码，现在不会有冲突。

---

### ⚠️ **方法 2：强制推送（慎用！）**
如果你确信远程的 `main` 分支可以被覆盖（例如你是唯一开发者，或者远程 `main` 里的内容不重要），可以强制推送：
```sh
git push origin main --force
```
但请小心，这会**覆盖远程分支上的所有更改**，其他开发者的代码可能会丢失。

---

### 🔍 **方法 3：查看冲突，手动合并**
如果 `git pull --rebase` 失败，说明你的代码与远程代码有冲突。可以尝试：
```sh
git pull origin main  # 先合并远程代码
```
如果有冲突：
1. Git 会提示你哪些文件有冲突，手动修改这些文件并保存。
2. 运行：
   ```sh
   git add .
   git commit -m "Resolve merge conflict"
   git push origin main
   ```

---

### **总结**
| 方法 | 适用情况 | 命令 |
|------|------|------|
| **方法 1（推荐）** | 本地代码落后于远程，需要同步 | `git pull --rebase origin main` 然后 `git push origin main` |
| **方法 2（慎用）** | 确定可以覆盖远程分支（无其他开发者） | `git push origin main --force` |
| **方法 3** | 远程代码与本地代码冲突，需手动解决 | `git pull origin main` + 解决冲突 |

如果你不确定该用哪个方法，可以先试 **方法 1**，如果报错，再尝试 **方法 3**。**只有当你非常确定要覆盖远程代码时，才使用方法 2！** 🚀

#  `git remote` 的作用
你可能是想问 `git remote` 的作用？  

### **`git remote` 用于管理远程仓库（Remote Repository）**
它允许你查看、添加、删除或修改远程仓库的 URL。  

---

## **1. 查看当前的远程仓库**
```sh
git remote -v
```
示例输出：
```
origin  https://github.com/username/repo.git (fetch)
origin  https://github.com/username/repo.git (push)
```
这表示你的本地仓库连接到了 `https://github.com/username/repo.git`，并且远程仓库的名字是 `origin`。

---

## **2. 添加远程仓库**
如果你的项目还没有远程仓库，可以用以下命令添加：
```sh
git remote add origin https://github.com/username/repo.git
```
这里 `origin` 是远程仓库的名称，你也可以换成别的名字。

---

## **3. 修改远程仓库的 URL**
如果远程仓库的地址变了，可以修改：
```sh
git remote set-url origin https://github.com/newuser/newrepo.git
```

---

## **4. 删除远程仓库**
如果你想移除远程仓库（不影响本地文件）：
```sh
git remote remove origin
```

---

## **5. 查看远程仓库的详细信息**
```sh
git remote show origin
```
示例输出：
```
* remote origin
  Fetch URL: https://github.com/username/repo.git
  Push  URL: https://github.com/username/repo.git
  HEAD branch: main
  Remote branches:
    main        tracked
```

---

## **6. 推送代码到远程仓库**
```sh
git push -u origin main
```
- `origin` 是远程仓库的名称  
- `main` 是分支名称  
- `-u` 让 Git 记住这个远程分支，后续可以直接 `git push`  

---

### **总结**
| 命令 | 作用 |
|------|------|
| `git remote -v` | 查看所有远程仓库 |
| `git remote add <name> <url>` | 添加远程仓库 |
| `git remote set-url <name> <new-url>` | 修改远程仓库 URL |
| `git remote remove <name>` | 删除远程仓库 |
| `git remote show <name>` | 查看远程仓库详细信息 |
| `git push -u <remote> <branch>` | 推送分支到远程 |

---

如果你是想问 `git remote` 相关的其他问题，可以告诉我你的具体需求！ 🚀

# `target_link_libraries` 和 `target_link_directories` 用于不同的目的
在 CMake 中，`target_link_libraries` 和 `target_link_directories` 用于不同的目的：  

---

## **1. `target_link_libraries`（正确方式）**
用于**将库链接到目标**，告诉编译器**使用哪些库**。  
```cmake
target_link_libraries(<target> <PRIVATE|PUBLIC|INTERFACE> <libraries>)
```
### **示例**
#### **静态库 `mylib`**
```cmake
add_library(mylib STATIC lib.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```
#### **可执行文件 `my_project`**
```cmake
add_executable(my_project main.cpp)
target_link_libraries(my_project PRIVATE mylib)
```
- **`mylib` 会正确链接到 `my_project`**。
- **头文件路径** 也会继承（如果 `mylib` 头文件路径是 `PUBLIC` 或 `INTERFACE`）。

---

## **2. `target_link_directories`（通常不需要）**
用于**指定库搜索目录**，告诉编译器去哪里找 `.lib` 或 `.a` 文件。  
```cmake
target_link_directories(<target> <PRIVATE|PUBLIC|INTERFACE> <directory>)
```
### **示例**
如果 `mylib` 是一个**预编译的**第三方库（如 `libs/` 目录下的 `.lib` 文件），则可以：
```cmake
target_link_directories(my_project PRIVATE ${CMAKE_SOURCE_DIR}/libs)
target_link_libraries(my_project PRIVATE mylib)
```
但如果 `mylib` 是在 **CMake 内部构建的库**，则**不需要 `target_link_directories`**，因为 CMake 自动知道库的位置。

---

## **什么时候使用 `target_link_directories`？**
1. **当库是预编译的**（没有 `add_library()`，只有 `.lib` 或 `.a`）。  
2. **手动指定库路径**（但 `find_package()` 更推荐）。  

## **什么时候用 `target_link_libraries`？**
✅ **几乎所有情况下**都应该使用 `target_link_libraries`，如果库是 CMake 内部构建的。

---

### **总结**
| **用法** | **适用场景** | **是否推荐** |
|----------|------------|-------------|
| `target_link_libraries` | 连接 **CMake 构建的库**（`add_library()` 生成的）| ✅ 推荐 |
| `target_link_directories` | 指定 **预编译库的路径**（手动 `.lib/.a`） | ⚠️ 仅在必须时使用 |

**在你的例子里，应该这样用：**
```cmake
target_link_libraries(my_project PRIVATE mylib)  # 直接链接 CMake 生成的 mylib
```
而 **不需要**：
```cmake
target_link_directories(my_project PUBLIC mylib)  # ❌ 这是错误的
```

这样，CMake 就能正确找到 `mylib`，并自动处理头文件路径！ 🚀

# 由于编码导致的错误&解决方法
> 把文件的编码格式从UTF-8调整为UTF-8 BOM
```
PS E:\Visual Studio Code\my_project\build> cmake ..
-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.26100.
-- Boost_INCLUDE_DIRS: E:/ThirdPartyPackages/vcpkg/installed/x64-windows/include
-- Boost_LIBRARIES:
-- Configuring done (0.0s)
-- Generating done (0.1s)
-- Build files have been written to: E:/Visual Studio Code/my_project/build
-- Configuring done (0.0s)
-- Generating done (0.1s)
-- Build files have been written to: E:/Visual Studio Code/my_project/build
-- Build files have been written to: E:/Visual Studio Code/my_project/build
PS E:\Visual Studio Code\my_project\build> cmake --build .
适用于 .NET Framework MSBuild 版本 17.13.19+0d9f5a35a

  mylib.vcxproj -> E:\Visual Studio Code\my_project\build\libs\Debug\mylib.lib
  main.cpp
E:\Visual Studio Code\my_project\src\main.cpp(1,1): error C2220: 以下警告被视为错误 [E:\Visual Studio Code\my_project\build\src\my_project.vcxproj]
E:\Visual Studio Code\my_project\src\main.cpp(1,1): warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失 [E:\Visual Studio Code\my_project\build\src\my_
project.vcxproj]
```
