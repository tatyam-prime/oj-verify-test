# oj-verify のはじめかた

1. 空のリポジトリを作る
2. Settings → Actions → Workflow permissions を "Read & Write" に設定
3. リポジトリを手元に clone
4. [`.verify-helper/config.toml`](.verify-helper/config.toml), [`.github/workflows/verify.yml`](.github/workflows/verify.yml), [`.github/workflows/requirements.txt`](.github/workflows/requirements.txt) をコピーし、commit & push
5. Settings → Pages → Build and deployment → Branch を `gh-pages` に設定
6. Code → About の設定で、`Use your GitHub Pages website` を true に
7. リンク先にライブラリのページができる

## 手元環境

1. `brew install pipx` / `sudo apt install pipx`
2. `pipx install online-judge-verify-helper`
3. `oj-verify run` でライブラリをチェック
4. `oj-bundle -I /path/to/your/library main.cpp` でライブラリを展開
