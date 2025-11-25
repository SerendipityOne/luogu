import os


def delete_exe_files(directory):
    """
    删除指定目录及其子目录下的所有.exe文件。

    :param directory: 要搜索的目录路径
    """
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".exe"):
                file_path = os.path.join(root, file)
                try:
                    os.remove(file_path)
                    print(f"已删除文件: {file_path}")
                except Exception as e:
                    print(f"删除文件时出错: {file_path}, 错误信息: {e}")


# 使用示例，将'your_directory_path'替换为你要删除.exe文件的实际目录路径
your_directory_path = 'E:\\C&C++\\luogu'
delete_exe_files(your_directory_path)
