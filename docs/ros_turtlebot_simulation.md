# TurtleBotシミュレーション（UbuntuおよびWindows）

## Dockerコンテナーの作成
- GUIに対応したROS用のDockerコンテナーを作成する。
  ```
  《Ubuntu》
  $ docker run -it -e="DISPLAY" -e="QT_X11_NO_MITSHM=1" -v="/tmp/.X11-unix:/tmp/.X11-unix:rw" --name ros_gui ros:melodic-robot-bionic /bin/bash
  《Windows》
  > docker run -it -e DISPLAY=host.docker.internal:0 --name ros_gui ros:melodic-robot-bionic /bin/bash
  ```
  - 再度コンテナーに入る時は、
    ```
    $ docker container exec -it ros_gui /bin/bash
    ```
- GUIを用いるので、Dockerのページを復習し、必要な設定を行う。

# シミュレーションの準備
- 関連があるROSパッケージをインストールする。
  ```
  # sudo apt update
  # sudo apt -y upgrade
  # sudo apt -y install ros-melodic-joy ros-melodic-teleop-twist-joy ros-melodic-teleop-twist-keyboard ros-melodic-laser-proc ros-melodic-rgbd-launch ros-melodic-depthimage-to-laserscan ros-melodic-rosserial-arduino ros-melodic-rosserial-python ros-melodic-rosserial-server ros-melodic-rosserial-client ros-melodic-rosserial-msgs ros-melodic-amcl ros-melodic-map-server ros-melodic-move-base ros-melodic-urdf ros-melodic-xacro ros-melodic-compressed-image-transport ros-melodic-rqt-image-view ros-melodic-gmapping ros-melodic-navigation ros-melodic-interactive-markers
  ```
- ロボット用のROSパッケージをインストールする。
  ```
  # sudo apt -y install ros-melodic-dynamixel-sdk
  # sudo apt -y install ros-melodic-turtlebot3-msgs
  # sudo apt -y install ros-melodic-turtlebot3
  ```
- シミュレーション用のROSパッケージをインストールする。
  ```
  # sudo apt -y install ros-melodic-turtlebot3-simulations
  # sudo apt -y install ros-melodic-rviz
  ```
- ロボットのモデルを指定する。
  ```
  # echo "export TURTLEBOT3_MODEL=burger" >> ~/.bashrc
  # source ~/.bashrc
  ```

## シミュレーションの実行
- ターミナルを2つ使用する。

### 1つ目
- 基本となる環境変数を設定する。
  ```
  # source /ros_entrypoint.sh
  ```
- シンプルなシミュレーター（RViz）を起動する。
  ```
  # roslaunch turtlebot3_fake turtlebot3_fake.launch
  ```

### 2つ目
- 基本となる環境変数を設定する。
  ```
  # source /ros_entrypoint.sh
  ```
- 制御用のROSノードを起動する。
  ```
  # roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  ```
  - wキーやxキーでロボットを操作できる。


## 付録：物理演算エンジン付きシミュレーター
- 必要なパッケージをインストールする。
  ```
  # sudo apt -y install ros-melodic-gazebo-ros-pkgs
  ```
- ターミナルを3つ使用する。

### 1つ目の代わり
- 基本となる環境変数を設定する。
  ```
  # source /ros_entrypoint.sh
  ```
- 物理演算エンジンが付いたシミュレーター（Gazebo）を起動する。
  ```
  # roslaunch turtlebot3_gazebo turtlebot3_empty_world.launch
  や
  # roslaunch turtlebot3_gazebo turtlebot3_world.launch
  や
  # roslaunch turtlebot3_gazebo turtlebot3_house.launch
  ```
  - 初回起動時は、必要なデータをダウンロードするため、時間が掛かる。数分掛かる。

### 3つ目
- 物理演算エンジンにより、仮想的に画像を取得したり、障害物との衝突判定を行ったり、実機に近いシミュレーションを実施することができる。
- センサーから取得される仮想的なデータはRVizで確認することができる。
  ```
  # source /ros_entrypoint.sh
  # rviz
  ```

[このページのトップへ](#)

[TurtleBotページへ](https://stl-apu.github.io/advanced_experiment_2022/ros_turtlebot)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
