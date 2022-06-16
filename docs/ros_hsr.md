# HSR
- トヨタ自動車は同社の生活支援ロボット「HSR」のシミュレーターを無償で公開しています。
- dockerとdocker-composeを用います。
- リポジトリーは[ここ](https://github.com/hsr-project/tmc_wrs_docker)にあります。
- 実行手順は英語または日本語のREADMEを確認してください。
  - [https://github.com/hsr-project/tmc_wrs_docker/blob/master/README.md](https://github.com/hsr-project/tmc_wrs_docker/blob/master/README.md)
  - [https://github.com/hsr-project/tmc_wrs_docker/blob/master/README_ja.md](https://github.com/hsr-project/tmc_wrs_docker/blob/master/README_ja.md)
- 以下にはUbuntuの手順を示します。
  - Macの場合はdocker for macをインストールしてください。
  - Windowsの場合はdocker for windowsをインストールしてください。

## docker-composeのインストール
- docker-composeをインストールする。
  ```
  $ sudo apt update
  $ sudo apt -y remove docker-compose
  $ COMPOSE_VERSION=$(wget https://api.github.com/repos/docker/compose/releases/latest -O - | grep 'tag_name' | cut -d\" -f4)
  $ sudo apt -y install curl
  $ sudo curl -L https://github.com/docker/compose/releases/download/1.16.1/docker-compose-`uname -s`-`uname -m` -o /usr/local/bin/docker-compose
  $ sudo chmod 755 /usr/local/bin/docker-compose
  ```
- インストールされたかを確認する。
  ```
  $ docker-compose --version
  ```

## リポジトリーのダウンロード
- クローンする。
  ```
  $ mkdir -p ~/hsr_ws/src
  $ cd hsr_ws/src/
  $ sudo apt -y install git
  $ git clone --recursive https://github.com/hsr-project/tmc_wrs_docker.git
  $ cd tmc_wrs_docker
  ```
- イメージをダウンロードする。ファイルサイズが大きいので注意してください。
  ```
  $ ./pull-images.sh
  ```

## シミュレーターの起動
- シミュレーターを起動します。
  ```
  $ docker-compose up
  ```
- ウェブブラウザーを用いてシミュレーター（gazebo）等を確認することができます。
  - シミュレーター　[http://localhost:3000](http://localhost:3000)
  - IDE　[http://localhost:3001](http://localhost:3001)
  - Jupyter Notebook [http://localhost:3002](http://localhost:3002)
- シミュレーターを開き、再生ボタン（三角ボタン）を押してシミュレーションを開始してください。
- IDEの［Terminal］→［New Terminal］でターミナルを開き、下記のコマンドでRVizを起動してください。
  ```
  $ rviz -d $(rospack find hsrb_rosnav_config)/launch/hsrb.rviz
  ```
- シミュレーターを開き、RVizの『2D Nav Goal』を使ってHSRを制御することができます。

## Dockerホストとの接続
- Dockerホストで下記のスクリプトを実行することで、ホストから制御することもできます。
  ```
  $ cd hsr_ws/src/tmc_wrs_docker
  $ source ./set-rosmaster.sh
  ```
- 試しにrostopicコマンドでHSRのROSトピックを購読できることを確認してください。
  ```
  $ rostopic list
  ```

  [このページのトップへ](#)

  [応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
