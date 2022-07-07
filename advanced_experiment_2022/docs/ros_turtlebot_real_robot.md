# 実機（Ubuntuのみ）

## Dockerコンテナーの作成
- hostネットワークに接続したROS用のDockerコンテナーを作成する。
  ```
  $ docker run -it --net host --cap-add=NET_ADMIN --name ros_host_admin ros:melodic-robot-bionic /bin/bash
  ```
  - オプションdが付いていないので、コンテナーを作成しつつ、コンテナーに入る。

## リモート・コンピューターの設定
- 関連があるROSパッケージをインストールする。
  ```
  # sudo apt update
  # sudo apt -y upgrade
  # sudo apt -y install ros-melodic-joy ros-melodic-teleop-twist-joy ros-melodic-teleop-twist-keyboard ros-melodic-laser-proc ros-melodic-rgbd-launch ros-melodic-depthimage-to-laserscan ros-melodic-rosserial-arduino ros-melodic-rosserial-python ros-melodic-rosserial-server ros-melodic-rosserial-client ros-melodic-rosserial-msgs ros-melodic-amcl ros-melodic-map-server ros-melodic-move-base ros-melodic-urdf ros-melodic-xacro ros-melodic-compressed-image-transport ros-melodic-rqt* ros-melodic-gmapping ros-melodic-navigation ros-melodic-interactive-markers
  ```
- ロボット用のROSパッケージをインストールする。
  ```
  # sudo apt -y install ros-melodic-dynamixel-sdk
  # sudo apt -y install ros-melodic-turtlebot3-msgs
  # sudo apt -y install ros-melodic-turtlebot3
  ```
- ロボットのモデルを指定する。
  ```
  # echo "export TURTLEBOT3_MODEL=burger" >> ~/.bashrc
  # source ~/.bashrc
  ```
- 無線ネットワークを「STL-AE」に切り替える。
  - パスワードは教員またはTAから教えてもらう。
  - 実機実験を終えたら、元の無線ネットワークに戻しておく。
- コンピューターのIPアドレスを確認する。
  ```
  # ip a
  ```
- ROS用の環境変数を設定する。
  ```
  《記法》
  $ export ROS_MASTER_URI=http://ロボットのIPアドレス:11311
  $ export ROS_HOSTNAME=コンピューターのIPアドレス
  《実例》
  $ export ROS_MASTER_URI=http://10.0.1.12:11311（※ロボットのIPアドレス）
  $ export ROS_HOSTNAME=10.0.1.21
  ```
  - ロボットのIPアドレスは教員やTAの指示に従ってください。
  - hostネットワークに接続しているので、『コンピューターのIPアドレス＝DockerホストのIPアドレス＝DockerコンテナーのIPアドレス』となります。
- 環境変数が正しく設定されていることを確認する。
  ```
  $ printenv | grep ROS
  ```

## ロボットの制御
- 教員またはTAに「ロボットを動かしたい」と伝える。
  - 教員またはTAがロボット内でROSマスター等を起動する。
- 基本となる環境変数を設定する。
  ```
  # source /ros_entrypoint.sh
  ```
- 制御用のROSノードを起動する。
  ```
  $ roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  ```

## ファイヤーウォールの設定
- 恐らく初期設定のままではロボットの中で起動しているROSマスターと通信できないので、ファイヤーウォールの設定を変更する。
- ufwコマンドをインストールする。
  ```
  # sudo apt -y install ufw
  ```
- ファイヤーウォールの状態を確認する。
  ```
  # sudo ufw status numbered
  ```
- IPアドレス指定でポートを開放する。
  ```
  《記法》
  # sudo ufw allow from ロボットのIPアドレス
  《実例》
  # sudo ufw allow from 10.0.1.12
  ```
- ファイヤーウォールを有効化する。
  ```
  # sudo ufw enable
  ```
- 再度、ファイヤーウォールの状態を確認する。
  ```
  # sudo ufw status numbered
  ```

[このページのトップへ](#)

[TurtleBotページへ](https://stl-apu.github.io/advanced_experiment_2022/ros_turtlebot)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
