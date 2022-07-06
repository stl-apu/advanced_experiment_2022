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

## Gitの設定
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
- 名前とメールアドレスが設定されていることを確認する。
  ```
  $ git config -l
  ```
  - Gitの設定を変更したい時は再度`$ git config`を編集する。

## GitHubの設定
- clone、pull、pushなどを実行できるよう、SSH接続（鍵認証）の設定を行います。
- 下記のディレクトリーにid_rsaとid_rsa.pubが存在することを確認します。
  ```
  $ ls ~/.ssh
  ```
  - 存在しない場合は作成します。パスフレーズは無しで大丈夫です。
    ```
    $ cd ~/.ssh
    $ ssh-keygen -t rsa
    ```
    - ディレクトリーも存在しない場合は作成します。
      ```
      $ mkdir ~/.ssh
      ```
    - コマンドssh-keygenが無い場合はパッケージをインストールします。
      ```
      $ sudo apt update
      $ sudo apt -y install openssh-server
      ```
- 下記のコマンドで公開鍵（id_rsa.pub）の内容をクリップボードにコピーする。
  ```
  $ cat ~/.ssh/id_rsa.pub | xsel -bi
  ```
  - コマンドxselが無い場合はパッケージをインストールする。
    ```
    $ sudo apt update
    $ sudo apt -y install xsel
    ```
- GitHubのウェブサイトを開く。
  - https://github.com/settings/ssh
- ［Settings］→［SSH and GPG keys］へと進み、［SSH keys］の所にあるボタン「New SSH key」を押す。
- 公開鍵の内容を記入欄「Key」の中にペーストし、登録する。
  - 記入欄「Title」にはコンピューター名などを記入する。
- 正常に接続できるかを確認する。
  ```
  $ ssh -T git@github.com
  ```
  - 「You've successfully authenticated, but GitHub does not provide shell access.」と表示されればOK！
  - 「Are you sure you want to continue connecting (yes/no/[fingerprint])?」と聞かれた場合は「yes」と回答する。

## 全体ダウンロード
- ROSでは、プログラムをワークスペースのsrcに置くので、ディレクトリーを移動する。
  ```
  $ cd ~/catkin_ws/src
  ```
- サブコマンドcloneでプログラムをコピー（初回ダウンロード）する。
  ```
  $ git clone git@github.com:stl-apu/advanced_experiment_2022.git
  ```
- コマンドlsでディレクトリー「advanced_experiment_2022」が存在することを確認する。
  ```
  $ ls
  ```

## 差分アップロード
- ディレクトリー「advanced_experiment_2022」に移動する。
  ```
  $ cd advanced_experiment_2022
  ```
- ブランチの一覧を確認する。
  ```
  $ git branch
  ```
  - mainのみが存在する。
- ブランチ「develop」に移動する。
  ```
  $ git checkout develop
  ```
- ブランチ「develop」に移動したことを確認する。
  ```
  $ git status
  ```
- ブランチの一覧を確認する。
  ```
  $ git branch
  ```
  - mainとdevelopが存在する。
- 自分用のブランチ（feature/学籍番号）を作成しながら移動する。
  ```
  《記法》
  $ git checkout -b ブランチ名
  《実例》
  $ git checkout -b feature/2020311000
  ```
- テキストエディター（geditなど）でtest.txtを開き、「Local 1」と追記し、保存する。
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
- pushする。
  ```
  《記法》
  $ git push origin ブランチ名
  《実例》
  $ git push origin feature/2020311000
  ```
- GitHubのウェブサイトを開き、自分用のブランチ（例：feature/2020311000）を確認する。「Local 1」が反映されていたらOK！

## 競合の解消
- 他のメンバーによってTXTファイルが編集されたことを再現するため、GitHubのウェブサイト上でリモート側のファイルを編集する。
- test.txtを選択し、ペンの形のアイコン（Edit file）から編集する。「Remote 1」と追記し、Commit（保存）する。
- 再度、ローカル側でテキストエディター（geditなど）でtest.txtを開き、「Local 2」と追記し、保存する。
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
- Pushすると、エラーが発生する。
  ```
  $ git push origin feature/2020311000
  ```
  - PullしてからでないとPushできない。
- Pullすると、別のエラーが発生する。
  ```
  $ git pull origin feature/2020311000
  ```
  - 複数人が同時に同じファイルを編集すると、競合（conflict）が発生する。
- テキストエディター（geditなど）でtest.txtを開き、競合を解消し、保存する。
  ```
  $ gedit test.txt
  ```
  - 今回は「Local 2」の方を残すことにします。
    - 実際には研究開発グループ内で修正方針を検討する必要があります。
  - 「\<\<\<」や「\>\>\>」などの記号（競合マーカー／コンフリクトマーカー）は削除します。
  - 最終的に、ファイルの内容は下記の通りとなります。
  ```
  Test
  Local 1
  Local 2
  ```
- Pushする。
  ```
  $ git add test.txt
  $ git commit -m "Update test.txt"
  $ git push origin feature/2020311000
  ```
- ブランチ「main」に戻しておく。
  ```
  $ git checkout main
  ```

## 補足1：ブランチの結合
- ブランチmain（master）が本番環境となります。
- feature → develop → masterと、プログラムをサブコマンドMergeで結合する必要があります。
- 研究開発リーダー（責任者）が行う作業なので、応用実験では割愛します。
- 将来、研究開発リーダーになりたい人は学習を継続してください。

## 補足2：Gitクライアント
- GitHub Desktopを使えば、GUIで管理できます。
- Git機能を搭載したソフトウェアも多いです。Atomなど…。

[このページのトップへ](#)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
