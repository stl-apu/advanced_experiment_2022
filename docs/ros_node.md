# ROSノード

## ROSノードを用いたトピック通信
- 応用実験用のROSパッケージ「advanced_experiment_2022」をcloneしたあとに実行してください。

## 準備
- ROSパッケージをcatkin_makeコマンドを用いてビルドします。
  ```
  $ docker exec -it ubuntu /bin/bash
  $ cd ~/catkin_ws
  $ catkin_make
  ```

- 環境変数DISPLAYが設定されていることを確認する。設定されていないと、ホストOSにGUIの表示を依頼できない。
  ```
  $ echo $DISPLAY
  ```
  - IPアドレスがホストOSと異なっていた場合は変更する。
    ```
    《記法》
    $ export DISPLAY=IPアドレス:ディスプレイ番号.スクリーン番号
    や
    $ export DISPLAY=IPアドレス:ディスプレイ番号
    《実例》
    $ export DISPLAY=172.31.233.193:0.0
    や
    $ export DISPLAY=172.31.233.193:0
    ```

### 1つ目：ROSマスターの起動
- roscoreを起動します。
  ```
  $ docker exec -it ubuntu /bin/bash
  $ source ~/catkin_ws/devel/setup.bash
  $ roscore
  ```

### 2つ目：ROSトピックの購読
- listenerを起動します。
  ```
  $ docker exec -it ubuntu /bin/bash
  $ source ~/catkin_ws/devel/setup.bash
  $ rosrun advanced_experiment listener
  ```

### 3つ目：ROSトピックの出版
- talkerを起動します。
  ```
  $ docker exec -it ubuntu /bin/bash
  $ source ~/catkin_ws/devel/setup.bash
  $ rosrun advanced_experiment talker
  ```

### 4つ目：ROSノードの確認  
- ツール「rqt_graph」でROSノード同士の繋がりを確認します。
  ```
  $ docker exec -it ubuntu /bin/bash
  $ source ~/catkin_ws/devel/setup.bash
  ```
  ```
  《正式な方法》
  $ rosrun rqt_graph rqt_graph
  《簡便な方法》
  $ rqt_graph
  ```
- 「/talker」という名前のROSノードと、「/listener」という名前のROSノードが、ROSトピック「/chatter」で繋がっていることが確認できると思います。このトピックが文字情報を伝達することで、2つのノードが連携することができます。
- 閉じるボタンか「Ctrlキー」＋「cキー」でrqt_graphを停止することができます。

[このページのトップへ](#)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
