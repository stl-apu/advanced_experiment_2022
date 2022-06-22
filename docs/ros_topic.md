# ROSトピック
- ROSの基本となるトピック通信について学びます。
- 4つのターミナル（コマンドプロンプト）を使用し、コマンドを用いたトピック通信を体験します。
- 3つ目のターミナルからトピックを出版（publish）し、2つ目のターミナルで購読（Subscribe）します。

## 1つ目：ROSマスターの起動
- Dockerコンテナーに入ります。
  ```
  $ docker exec -it ubuntu /bin/bash
  ```
- ROSマスターを起動します。
  ```
  # roscore
  ```

## 2つ目：ROSトピックの購読
- 別のターミナルを開きます。
- Dockerコンテナーに入ります。
- トピック「/turtle1/cmd_vel」を購読してみます。この時点では何も出版されていないので、何も表示されません。
  ```
  $ rostopic echo /turtle1/cmd_vel
  ```
  - 終了する時は「Ctrlキー」＋「cキー」を押します。

## 3つ目：ROSトピックの出版
- 別のターミナルを開きます。
- Dockerコンテナーに入ります。
- トピック「/turtle1/cmd_vel」を出版してみます。出版すると、2つ目のターミナルに移動量が表示されます。
  ```
  $ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -- '[0.0,0.0,0.0]' '[0.0,0.0,3.14]'
  ```  
  - 前半の3つの値で並進移動量（1つ目の値で前進・後進）を、後半の3つの値で回転移動量（6つ目の値で進行方向）を指定します。
  - 回転方向は、反時計回りが正になるので注意しましょう。
- 上記のコマンドでは、毎回「Ctrlキー」＋「cキー」で終了する必要があります。下記のようにオプション「-1」を付けることで、１回実行した後に自動的で終了するようにできます。  
  ```
  $ rostopic pub -1 /turtle1/cmd_vel geometry_msgs/Twist -- '[1.0,0.0,0.0]' '[0.0,0.0,0.0]'
  ```
  - 数回実行したい場合はオプションrを使用する。

## 4つ目：ROSトピックの確認
- 別のターミナルを開きます。
- Dockerコンテナーに入ります。
- 利用可能なトピックの一覧を確認します。トピック「/rosout」などが存在していると思います。
  ```
  $ rostopic list
  ```
- トピック「/turtle1/cmd_vel」のメッセージ型を確認します。「geometry_msgs/Twist」という型であることが分かります。
  ```
  $ rostopic type /turtle1/cmd_vel
  ```
  - intなどの単純な型（std_msgs/Int32）も存在しますが、ROSはロボット用のソフトウェアなので、いくつかの変数がまとまった構造体のような型を利用することが多いです。
- メッセージ型「geometry_msgs/Twist」を構成する要素を確認します。2つの3次元ベクトル（linearとangular）で構成されており、それぞれの値はfloatであることが分かります。  
  ```
  $ rosmsg show geometry_msgs/Twist
  ```
  - パイプで複数のコマンドを組み合わせると便利です。
    ```
    $ rostopic type /turtle1/cmd_vel | rosmsg show
    ```
- PublishersやSubscribersを確認します。指定したトピックを出版しているノードや購読しているノードを確認することができます。
  ```
  《記法》
  $ rostopic info トピック名
  《実例》
  $ rostopic info /turtle1/cmd_vel
  ```  

[このページのトップへ](#)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
