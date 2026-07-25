# Paket Converter

Uma ferramenta nativa C++/Qt6 que converte pacotes `.deb` e `.rpm` em
pacotes **Arch Linux** instaláveis (`.pkg.tar.zst`) — com detecção real
de dependências, instalação automática de bibliotecas pelos repositórios
e um histórico de instalação persistente.

## Por quê?

Alguns programas (jogos, ferramentas especiais) só existem como `.deb`
(Debian/Ubuntu) ou `.rpm` (Fedora/openSUSE), não nos repositórios Arch.
Esta ferramenta os converte sem AUR — usando apenas fontes oficiais do Arch.

## Recursos

- **deb/rpm → Arch** : extrai, detecta as bibliotecas necessárias via
  `readelf` + `pkgfile` (soname exato, sem tabelas adivinhadas)
- **Instalação automática** das dependências de repositório via `pacman -S --asdeps`
- **Caminho do binário** : `/usr/games/` é movido para `/usr/bin/`
- **Aviso** para pacotes de dados puros (sem programa executável)
- **Janela de dica** na instalação se pacotes de dados extras
  (`-data`, `-common`) poderem estar faltando
- **Log copiável**, histórico de instalação persistente
- **Alternar Claro/Escuro** (padrão: claro)

## Compilar e instalar (do código-fonte, sem AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Depois **Paket Converter** aparece no menu do KDE
(categoria: Utilitário / Gerenciamento de pacotes).

## Uso

1. **Procurar** → selecione um arquivo `.deb` ou `.rpm`
2. **Construir pacote** (ou « Pacote + Fontes »)
3. **Instalar pacote** → digite a senha, pronto

## Notas

- Alguns projetos dividem jogos em programa + pacote `-data`.
  Se gráficos/sons faltarem após iniciar, converta também o
  pacote de dados correspondente.
- Bibliotecas que existem apenas no **AUR** (ex. `glc-lib`) não
  podem ser instaladas automaticamente — a ferramenta avisa.

## Dependências

`qt6-base` (inclui `qmake6` para compilar), `pacman`, `file`, `binutils`, `cpio`, `libarchive`
