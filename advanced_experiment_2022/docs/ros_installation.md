# ROSの環境構築
- Ubuntu 18.04（Bionic Beaver）に対応したROS 18.04（Melodic Morenia）をインストールします。

## ROSのインストール
- 必要なコマンドを予めインストールしておきます。前述のコマンドsudoも必要です。
  ```
  # sudo apt update
  《lsb_release》
  # sudo apt -y install lsb-release
  《curl》
  # sudo apt -y install curl
  《gnupg》
  # sudo apt -y install gnupg
  ```
- 下記のコマンドを1行ずつコピー＆ペーストし、実行します。
  ```
  # sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros1-latest.list'
  # curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
  # sudo apt update
  # sudo apt -y install ros-melodic-desktop-full
  # echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
  # source ~/.bashrc
  ```
- 必要に応じて、関連ソフトウェアもインストールします。
  ```
  # sudo apt -y install python-rosinstall python-rosinstall-generator python-wstool build-essential
  ```

## 環境変数の確認
- ROSが正常にインストールできたことを確認します。  
  ```
  # printenv | grep ROS
  ```
  - 正常にインストールできていれば、下記のように出力されます。
  ```
  ROS_ETC_DIR=/opt/ros/melodic/etc/ros
  ROS_ROOT=/opt/ros/melodic/share/ros
  ROS_MASTER_URI=http://localhost:11311
  ROS_VERSION=1
  ROS_PYTHON_VERSION=2
  ROS_PACKAGE_PATH=/opt/ros/melodic/share
  ROSLISP_PACKAGE_DIRECTORIES=
  ROS_DISTRO=melodic
  ```

## 参考1
- rootユーザーで上手くインストールできない人は一般ユーザーでインストールしてみてください。
  ```
  《記法》
  # adduser ユーザー名
  # gpasswd -a ユーザー名 sudo
  # su - ユーザー名
  《実例》
  # adduser suzuki
  # gpasswd -a suzuki sudo
  # su - suzuki
  ```

## 参考2
- ROSが予めインストールされたDockerイメージも存在します。
- 下記のコマンドでイメージをダウンロードすることができます。
  ```
  $ docker pull ros:melodic-robot-bionic
  ```

[このページのトップへ](#)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
