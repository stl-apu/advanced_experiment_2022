# rosbagの利用
- bagファイルを作成するためのツールです。
- 時間と共に、出版されたROSトピックをデータとして記録することができます。
- 同じ実験を効率的に何度も繰り返すことができます。
  - 同じ出力を完全に再現することができます。

## 記録
- 記録したいノードを立ち上げます。
  ```
  $ roslaunch advanced_experiment turtle_mouse.launch --screen
  ```
- トピックの一覧を確認します。
  ```
  $ rostopic list
  ```
- 記録したいトピックを選択しながらrecordサブコマンドを実行します。
  ```
  《記法》
  $ rosbag record トピック名 -O ファイル名.bag
  《実例》
  $ rosbag record /turtle1/cmd_vel -O turtlesim.bag
  ```
- Ctrl＋cで記録を終了します。
  - bagファイルはrecordサブコマンドを実行したディレクトリーに生成されます。
- 他のノードも停止します。

## 確認
- infoサブコマンドで確認します。
  ```
  《記法》
  $ rosbag info ファイル名.bag
  《実例》
  $ rosbag info turtlesim.bag
  ```
  - 記録したかったトピックが正しく記録されているかを確認することができます。
  - 記録の長さも確認することができます。

## 再生
- ROSマスターを起動します。
  ```
  $ roscore
  ```
- rosbagファイルを再生します。
  ```
  《記法》
  $ rosbag play ファイル名.bag
  《実例》
  $ rosbag play turtlesim.bag
  ```
  - オプションl（--loop）を付けると繰り返し再生できます。
  - オプションr（--rate=）で再生速度の倍率を設定できます。速くすることも遅くすることもできます。
    - 再生速度を遅くすることで、ロースペックのPCでもシミュレーションを実行することができます。また、デバッグが行いやすくなるという利点もあります。
- まず、`rostopic echo`コマンドで正常に出力されていることを確認してください。
- そして、turtlesimを起動し、ロボットが動くことを確認してください。
  ```
  $ rosrun turtlesim turtlesim_node
  ```

## 参考
- rqt_bagを使うとGUIでbagファイルを取り扱うことができます。興味がある人は試してみてください。

[このページのトップへ](#)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
