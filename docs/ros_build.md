# ROSのビルド

## ディレクトリーの作成
- 研究開発用ディレクトリーとしてcatkin_wsおよびsrcを作成します。
  ```
  # mkdir -p ~/catkin_ws/src
  ```

## プログラムのビルド
- catkin_makeコマンドを用いてビルドします。この時点では何もプログラムが無いので、すぐに100％になり、ビルドが完了すると思います。
  ```
  # cd ~/catkin_ws
  # catkin_make
  # echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
  # source ~/.bashrc
  ```
- 正常にビルドできていれば、下記のコマンドで「~/catkin_ws/devel」に移動します。
  ```
  # roscd
  ```

[このページのトップへ](#)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
