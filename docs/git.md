# Git
- Gitを利用して、応用実験で使用するプログラムをダウンロードする。
- Gitを利用して、応用実験のレポートを提出する。

## 準備
- ターミナルやコマンドプロンプトを開く。
- Dockerサービスを起動する。
- コンテナーに入る。
  ```
  $ docker exec -it ubuntu /bin/bash
  ```
- ページ「ROS Build」を参考にcatkin_wsなどのディレクトリーを作成する。

## 初回設定
- gitをインストールする。
  ```
  $ sudo apt -y install git
  ```
- gitがインストールされたことを確認する。
  ```
  $ git version
  ```
- ユーザーの名前とメールアドレスを登録する。
  ```
  《記法》
  $ git config --global user.name "名前"
  $ git config --global user.email "メールアドレス"

  《実例》
  $ git config --global user.name "Takuo Suzuki"
  $ git config --global user.email "takuo.suzuki@ist.aichi-pu.ac.jp"
  ```

## 全体ダウンロード
- ROSでは、プログラムをワークスペースのsrcに置くので、ディレクトリーを移動する。
  ```
  $ cd ~/catkin_ws/src
  ```
- cloneサブコマンドでプログラムをコピー（初回ダウンロード）する。
  ```
  $ git clone https://github.com/stl-apu/advanced_experiment_2021.git
  ```
- lsコマンドでディレクトリーadvanced_experiment_2021が存在することを確認する。
  ```
  $ ls
  ```

## 差分アップロード
- ディレクトリーadvanced_experiment_2021に移動する。
  ```
  $ cd advanced_experiment_2021
  ```
- ブランチの一覧を確認する。
  ```
  $ git branch
  ```
  - mainのみが存在する。
- ブランチ「develop」を作成する。
  ```
  $ git branch develop
  ```
- ブランチ「develop」に移動する。
  ```
  $ git checkout develop
  ```
- ブランチ「develop」に移動したことを確認する。
  ```
  $ git status
  ```
- 自分用のブランチを作成しつつ、移動する。
  ```
  《記法》
  $ git checkout -b feature/学籍番号

  《実例》
  $ git checkout -b feature/2019311000
  ```
- geditなどのテキストエディターでtest.txtを開き、「Local 1」と追記し、保存する。
  ```
  $ gedit test.txt
  ```
- 編集内容をcommitの対象に含める。
  ```
  $ git add test.txt
  ```
- commitする。
  ```
  《記法》
  $ git commit -m "コミット文"

  《実例》
  $ git commit -m "Update test.txt"
  ```
- pushする。GitHubのユーザー名とパスワードを入力する。
  ```
  $ git push origin feature/2019311000
  ```
- GitHubのウェブサイトを開き、ブランチ「feature/2019311000」を確認する。「Local 1」が反映されていたらOK！

## 競合の解消
- 他のメンバーによってTXTファイルが編集されたことを再現するため、GitHubのウェブサイト上でリモート側を編集する。
- test.txtを選択し、ペンの形のアイコン（Edit file）から編集する。「Remote 1」と追記し、Commit（保存）する。
- 再度、ローカル側でテキストエディターでtest.txtを開き、「Local 2」と追記し、保存する。
  ```
  $ gedit test.txt
  ```
- 編集内容をcommitの対象に含める。
  ```
  $ git add test.txt
  ```
- Commitする。
  ```
  $ git commit -m "Update test.txt"
  ```
- Pushする。エラーが発生する。
  ```
  $ git push origin feature/2019311000
  ```
  - PullしてからでないとPushできない。
- Pullする。別のエラーが発生する。
  ```
  $ git pull origin feature/2019311000
  ```
  - 複数人が同時に同じファイルを編集すると、競合（conflict）が発生する。
- テキストエディターでtest.txtを開き、競合を解消し、保存する。
  ```
  $ gedit test.txt
  ```
  - 今回は「Local 2」の方を残すことにします。
  - 「<<<」や「>>>」などの記号（競合マーカー／コンフリクトマーカー）は削除します。
  - 最終的なファイルは下記のとおりとなります。
  ```
  Test
  Local 1
  Local 2
  ```
- Pushする。
  ```
  $ git add test.txt
  $ git commit -m "Update test.txt"
  $ git push origin feature/2019311000
  ```
- ブランチを「main」に戻しておく。
  ```
  $ git checkout main
  ```


## ブランチの結合
- ブランチmaster（main）が本番環境となります。
- feature → develop → masterと、プログラムをMergeサブコマンドで結合する必要があります。
- 研究開発リーダー（責任者）が行う作業なので、応用実験では割愛します。
  - 将来、リーダーになりたい人は学習を続けてください。


## 設定変更
- Gitの設定を変更したいときはconfigファイルを開く。
```
$ cd ~/catkin_ws/src/advanced_experiment_2021
$ gedit .git/config
```


## 付録1：SSHの設定
- どのディレクトリーで行っても大丈夫です。
- 下記のディレクトリーにid_rsaとid_rsa.pubが存在することを確認します。
  ```
  $ ls ~/.ssh
  ```
  - 存在しない場合は作成します。パスフレーズは無しで大丈夫です。
    ```
    $ ssh-keygen -t rsa
    ```
    - ssh-keygenコマンドが無い場合はパッケージをインストールする。
      ```
      $ sudo apt update
      $ sudo apt -y install openssh-server
      ```
- 下記のコマンドで公開鍵の内容をクリップボードにコピーする。
  ```
  $ cat ~/.ssh/id_rsa.pub | xsel --clipboard --input
  ```
  - xselコマンドが無い場合はパッケージをインストールする。

    ```
    $ sudo apt update
    $ sudo apt -y install xsel
    ```
- GitHubのウェブサイトを開き、［Settings］→［SSH and GPG keys］→［SSH keys］へ進み、ボタン「New SSH key」を押す。
- 公開鍵の内容を記入欄「key」の中にペーストし、登録する。


## 付録2：Gitクライアント
- GitHub Desktopを使えば、GUIで管理できる。
- Git機能を搭載したソフトウェアも多い。


[このページのトップへ](#)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
