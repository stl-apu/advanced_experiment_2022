# Docker（Ubuntu）

## ソフトウェアのインストール
- Dockerをインストールする。
  ```
  $ sudo apt update
  $ sudo apt -y install docker.io
  ```
- コマンドdockerが実行できることを確認する。
  ```
  $ docker version
  ```

## ソケット通信の設定
- グループ「docker」にユーザーを追加する。
  ```
  $ sudo gpasswd -a $USER docker
  ```
- ソケット通信に関するファイルの所有者をグループ「docker」に変更する。
  ```
  $ sudo chgrp docker /var/run/docker.sock
  ```
- サービスDockerを再起動する。
  ```
  $ sudo service docker restart
  ```
- コンピューターを再起動する。
  ```
  $ sudo reboot
  ```
- 接続が許可されているクライアント（Docker Container）として「LOCAL:」があることを確認する。
  ```
  $ xhost
  access control enabled, only authorized clients can connect
  LOCAL:
  SI:localuser:ユーザー名
  ```
  - 「LOCAL:」が無い場合は追加する。
    ```
    $ xhost +local:
    ```
- 改めてDockerサービスを起動する。
  ```
  $ sudo service docker start
  ```

## イメージのダウンロード
- Ubuntu 18.04のイメージをダウンロードする。
  ```
  $ docker image pull ubuntu:18.04
  ```
- Ubuntu 18.04のイメージが存在することを確認する。
  ```
  $ docker image ls
  ```

## コンテナーの作成→テスト
- イメージを用いてコンテナーを作成し、起動する。オプションnameでコンテナーに対して名前（例：ubuntu）を付けておく。
  ```
  $ docker container run -itd --env="DISPLAY" --env="QT_X11_NO_MITSHM=1" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --name ubuntu ubuntu:18.04 /bin/bash
  ```
- コンテナー「ubuntu」が存在することを確認する。
  ```
  $ docker container ls -a
  ```
- コンテナー「ubuntu」に入る。
  ```
  $ docker container exec -it ubuntu /bin/bash
  ```
- コマンドsudoをインストールする。
  ```
  # su
  # apt update
  # apt -y install sudo
  # exit
  ```
- geditをインストールし、実行してみる。
  ```
  # sudo apt -y install gedit
  # gedit
  ```
  - libGLに関するエラーが発生する場合は、下記のコマンドを実行する。
    ```
    # export LIBGL_ALWAYS_INDIRECT=1
    ```
- x11-appsをインストールし、実行してみる。
  ```
  # sudo apt -y install x11-apps
  # xeyes
  ```
  - マウスカーソルを見続ける目が表示される。
  - 「Ctrl＋c」で終了できる。

## コンテナーの操作（今後のために）

### コンテナーの起動
- コンテナーを起動する。
  ```
  《記法》
  $ docker container start コンテナー名
  《実例》
  $ docker container start ubuntu
  ```

### コンテナーの停止
- コンテナーをコマンド`exit`で抜けてから、コンテナーを停止する。
  ```
  # exit
  ```
  ```
  《記法》
  $ docker container stop コンテナー名
  《実例》
  $ docker container stop ubuntu
  ```

### コンテナーの削除
- コンテナーを作り直す場合は、まず、サブコマンド`container ls`でコンテナーIDを確認する。そして、コンテナーを停止し、サブコマンド`container rm`で削除する。
  ```
  $ docker container ls -a --no-trunc
  ```
  ```
  《記法》
  $ docker container rm コンテナーID
  《実例》
  $ docker container rm 81ae65b0ac4296538f66d4037b18d36a2cc530b926eb0c9d3bce4a5a622ef003
  ```

[このページのトップへ](#)

[Dockerページへ](https://stl-apu.github.io/advanced_experiment_2022/docker)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
