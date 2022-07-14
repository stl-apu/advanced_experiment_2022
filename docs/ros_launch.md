# roslaunchの利用
- 毎回、複数のターミナルを開くのは面倒なので、普通はROSコマンド「roslaunch」を使用します。
- roslaunchコマンドでlaunchファイルを実行すると、複数のROSノードを1つのターミナルで起動することができます。
  - ROSマスターが起動していなかった場合は、自動的に起動してくれます。
  - ROSパラメーターも合わせて設定することができます。
- launchファイルはlaunchディレクトリーに置きます。

## 実行
- まず、launchディレクトリー内のturtle_test.launchを確認してみます。タグ<node>が2組あるので、2つのROSノードが起動することが分かります。
- 実行します。
  ```
  《記法》
  $ roslaunch パッケージ名 ファイル名.launch
  《実例》
  $ roslaunch advanced_experiment turtle_test.launch
  ```
  - screenオプションを付けると、ノードの出力（ROS_INFOなど）を確認できるようになります。
  ```
  $ roslaunch advanced_experiment turtle_test.launch --screen
  ```

## 変更
- マウスで操作するためのノードも起動するように変更してみましょう。
- turtle_test.launchをコピーし、turtle_mouse.launchを作成します。
- テキストエディター（geditなど）でturtle_mouse.launchを開きます。
  ```
  $ gedit turtle_mouse.launch
  ```
- 下記の1行を</launch>タグの前に追記し、保存してください。
  ```
  <node pkg="mouse_teleop" type="mouse_teleop.py" name="mouse_teleop" />
  ```
- 実行してみます。
  ```
  $ roslaunch advanced_experiment turtle_mouse.launch --screen
  ```
  - これだけだとマウスでロボットを操作することができません。トピック名が合っていないためです。ノード同士の繋がりを確認してみましょう。
    ```
    $ rqt_graph
    ```
- ノードを起動する時にトピック名を変更します。下記の通り、修正してください。
  ```
  <node pkg="mouse_teleop" type="mouse_teleop.py" name="mouse_teleop">
    <remap from="mouse_vel" to="/turtle1/cmd_vel"/>
  </node>
  ```
- マウスでロボットを操作できるようになったと思います。
- ROSパラメーターも設定してみましょう。
- 下記の3行をturtlesim_nodeを起動する<node>タグに追記し、保存してください。
  ```
  <param name="background_r" value="255"/>
  <param name="background_g" value="255"/>
  <param name="background_b" value="255"/>
  ```
- シミュレーターの背景が白になったと思います。
- 以上のように、ノード名を変更したりパラメーターを設定したりすることで、複数のノードを連携可能な状態で起動することができます。

## 要点
- ROSを理解する上で重要なのは、ROSノードを1つも開発せずにロボットを動作させることができたという点です。
- ROSはユーザー数が多いため、キー入力の取得や画像の取得など、多くの人が必要としている機能は既に実装・公開されています。
- そのため、自分が得意とする部分の開発に注力することができます。
- 自分が開発したROSノード（ROSパッケージ）を公開することで、直ぐに社会に貢献することができます。
- トヨタ自動車の生活支援ロボット「HSR」のプログラムは複数の研究機関が集まって開発していますが、愛県大グループでは人間や物体を認識するためのROSパッケージのみを開発しており、その他の部分はトヨタ自動車や他の研究機関が開発してくれたものを使っています。
- ROSを利用することで共同研究しやすくなったと言えますね。

[このページのトップへ](#)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
