# 2020年度後期プログラミング演習III

## 初めに

プログラミング演習IIIのLACSページは、[LACS プログラミング演習III][1]です。

## 環境の準備  
プログラミング演習IIと同様の環境で演習を行います。1〜3までは、プログラミング演習IIで実施済みと思います。
1. GitHubにアカウントを取得してください。
2. Gitをインストールしてください。
3. 自分のPCに開発環境（ソースエディタ、コンパイラ）を揃えてください。本演習では、
   - ソースエディタ：Visual Studio Code
   - コンパイラ：GNU C Compiler  
    
    を推奨します。WindowsでもMacでもLinux(演習室)でも同じ環境です。
4. このレポジトリ https://github.com/tomo-ozaki/2020psp3 を「Fork」してください．
5. Forkすると自分のGitHubにレポジトリのクローンが新規作成されます。https://www.github.com/(あなた)/2020psp3 となるでしょう。
6. developブランチを作成してください。ブランチの作成方法は[操作説明資料][2]の「ブランチの作成」を参照してください。
7. あなたのGitHubレポジトリのクローンを、自分のPCに新規作成してください。Visual Studio Codeで可能です。
8. Visual Studio Codeで、ブランチをdevelopに切り替えてください。ブランチの切替方法は[操作説明資料][2]の「ブランチ切替」を参照してください  
9. この後の「コミット」の準備のため，ターミナルで，以下の2つのコマンドを打って，メールアドレスと名前を設定してください．  
```
git config --global user.email あなたのメールアドレス
git config --global user.name あなたの名前
```
ついでに以下の設定もしておいてください．
```
git remote add upstream https://github.com/tomo-ozaki/2020psp3.git
git fetch upstream
```

### コンパイルの仕方

- 端末環境で`gcc -W -Wall k00.c -o k00`などとするとコンパイルがおこなわれ、正常にコンパイルされると`k00`という実行ファイルができます。
- 端末環境は、
  - linuxではultermとかxtermとかなんでも
  - windowsではGit for Windowsからインストールされたbashを使います。デスクトップで右クリックからショートカット作成して、「項目の場所」として
    `"C:\Program Files\Git\usr\bin\bash.exe" --login`
    を指定します。このショートカットからbash端末が起動します．起動したときに自分がいるディレクトリは`c:\Users\ログイン名`です。エクスプローラで確かめておきましょう
  - macでは，`ターミナル`というものが入っています。起動したときに自分がいるディレクトリなど確認しておきましょう。
- 文字コードはUTF-8を使用します。Windowsの場合、bash起動後、`chcp.com 65001`と打ち込んで、エンターキーを押してください。


## 演習の進め方
1. プログラムとレポートの作成
各課題について
    - ソースコード（k0*.c）
    - レポート（README.md）  

    を修正し、commit、pushしてください。Visual Studio Codeを利用したcommit、push操作については、[操作説明資料][2]の「Commit & Push」を参照してください。

2. 提出  
提出が可能な状態になったら、GitHubでPull Requestを作成します。Pull Requestの作成方法については、[操作説明資料][2]の「提出方法 Pull Request」を参照してください。なお、プルリクエストのコメントの先頭に、@tomo-ozakiと書くようにしてください。  
また、一つの課題で、複数の関数を実装する場合があります。このような場合、一つの実装が終わった段階で、Pull Requestを作成し、チェックを依頼することも可能です。


3. 結果の確認  
Pull Reuquestを尾崎(またはTA)がチェックし、必要に応じてコメントを入れます。GitHubで修正コメントを確認してください。確認方法は[操作説明資料][2]の「結果の確認」を参照してください。  
合格とならなかった場合、再度、修正を行い、commit、pushをした後で、再度、Pull Requestを作成してください。  
何度かやりとりし、OKになれば、尾崎(またはTA)がソースコードをmasterにマージします。
レポートを含め、合格になれば、レポートの履歴欄に、尾崎(またはTA)が合格と記載します。


## 課題について
課題は全部で6個(k01〜k06)あります。k00は動作確認用のサンプルです。一部の課題には、チャレンジ問題があります。ぜひ、チャレンジしてみてください。
- [課題1](k01/README.md)
- [課題2](k02/README.md)
- [課題3](k03/README.md)
- [課題4](k04/README.md)
- [課題5](k05/README.md)
- [課題6](k06/README.md)

## 課題の修正の取得  
尾崎が課題を修正した場合、LACSで通知します。
その場合、課題をダウンロードしたフォルダ((ローカルPCでの保存場所)/2020psp3)でbashを起動し、以下のコマンドを実行して、変更を取得してください。なお、"1. Upstreamの設定"は、一度実行すればよく、2回目からは実行する必要はありません。　　
1. Upstreamの設定
``` 
git remote add upstream https://github.com/tomo-ozaki/2020psp3.git
```

2. 変更の取得
```
git fetch upstream
git merge upstream/master
```


[1]:https://lacs.nagasaki-u.ac.jp/webapps/blackboard/execute/courseMain?course_id=_82376_1
[2]:Reference/プログラミング演習III_操作説明.pdf
