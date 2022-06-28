# ROSパラメーター
- ROSマスターが起動すると、ROSパラメーターサーバーも一緒に起動します。
- このサーバーを介して、グローバル変数のように全てのノードで利用可能な変数を共有することができます。

## Global parameters
- シミュレーター（turtlesim）を用いてグローバルパラメーターの仕組みを理解しましょう。

### 1つ目：ROSマスターの起動
- ROSマスターを起動します。

### 2つ目：シミュレーターの起動
- バーチャルなロボットとして、turtlesimノードを起動します。

### 3つ目：グローバル変数の利用
- どんなROSパラメーターが存在するかを確認してみます。
  ```
  $ rosparam list
  ```
- 具体的な値を確認してみます。
  ```
  $ rosparam get /turtlesim/background_b
  ```
- 値を変更してみます。
  ```
  $ rosparam set /turtlesim/background_b 0
  ```  
- パラメーターはノードを生成した時に読み込まれるため、強制的に再読み込みを行い、変更内容を反映します。
  ```
  $ rosservice call /clear
  ```
  - シミュレーターの背景色が変わります。  


## Private parameters
- 改良版のtalker（talker_with_parameter）を用いてプライベートパラメーターの仕組みを理解しましょう。
- プライベートパラメーターを使用することで、ノードを生成する時に値を変更することができます。
  - 例えば、ロボットの大きさなどの情報を後から設定することで、同じプログラムで多種多様なロボットを動かすことができます。
  - 他にも、画像処理の閾値や制御コントローラーのゲインを変更しながら連続的にシミュレーション実験を行うことができるので、効率的に研究を進めることができます。

### 1つ目：ROSマスターの起動
  - ROSマスターを起動します。

### 2つ目：listenerノードの起動
  - listenerノードを起動します。

### 3つ目：talkerノードの起動
  - talker_with_parameterを起動します。
    ```
    $ docker exec -it ubuntu /bin/bash
    $ source ~/catkin_ws/devel/setup.bash
    $ rosrun advanced_experiment talker_with_parameter
    ```
    - 「hello world?」と表示されます。
  - 1度、終了します。
  - 次にプライベートパラメーターを設定しながら起動します。先頭のアンダースコアがプライベートであることを表します。
    ```
    $ rosrun advanced_experiment talker_with_parameter _param:="hello world!"
    ```
    - 今度は「hello world!」と表示されます。
  - このような仕組みにより、ロボットに様々な文章を発話させることができます（→ヒューマン・ロボット・インタラクション）。


## Special keys
- ROSにも予約語のようなもの（「__name」など）が存在します。
- 下記のように実行することで、任意の名前でノードを起動することができます。
  ```
  $ rosrun turtlesim turtlesim_node __name:=foo
  ```
  - ROSシステム内では、同じ名前のノードは1つしか存在することができないので、同じ名前を指定すると上書きされてしまいます。
  - 逆に言えば、異なる名前を指定すれば、複数のロボットを同時に発生させることもできます。つまり、1台のキーボードや1個のマウスで複数台のロボットを操作できるようになります。

[このページのトップへ](#)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
