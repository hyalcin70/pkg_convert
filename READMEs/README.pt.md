# Paket Converter

Uma ferramenta nativa C++/Qt6 que converte pacotes `.deb` e `.rpm`
em pacotes **Arch Linux** instaláveis (`.pkg.tar.zst`) — com
detecção real de dependências, instalação automática de bibliotecas
dos repositórios e um histórico de instalação persistente.

> ⚠️ **Apenas para distribuições baseadas em Arch.** Este projeto é
> exclusivamente para distribuições **baseadas em Arch Linux**
> (Arch, Manjaro, EndeavourOS, …). Solicitações ou problemas sobre
> outras distribuições (Debian/Ubuntu, Fedora, openSUSE, …) **não**
> serão respondidos — a ferramenta gera pacotes `.pkg.tar.zst`, que
> só funcionam em sistemas baseados em Arch.

## Por quê?

Alguns programas (jogos, ferramentas especiais) só estão disponíveis
como `.deb` (Debian/Ubuntu) ou `.rpm` (Fedora/openSUSE), não nos
repos do Arch. Esta ferramenta os converte sem AUR — usando apenas
fontes oficiais do Arch.

## Recursos

- **deb/rpm → Arch** : extrai, detecta bibliotecas necessárias via
  `readelf` + `pkgfile` (soname exato, sem tabelas adivinhadas)
- **Instalação auto** de dependências via `pacman -S --asdeps`
- **Caminho do binário** : `/usr/games/` é movido para `/usr/bin/`
- **Aviso** para pacotes de dados puros (sem executável)
- **Popup de dica** na instalação se faltarem pacotes de dados
  adicionais (`-data`, `-common`)
- **Log copiável**, histórico de instalação persistente
- **Alternador Claro/Escuro** (padrão: claro)

## Por que pkg_convert em vez de debtap / rpmtoarch ?

Existem outros conversores (debtap, rpmtoarch). Veja por que o
pkg_convert é melhor para a maioria:

1. **Uma ferramenta para os dois formatos.** `debtap` só lida com
   `.deb` (falha em `.rpm` com *"not a valid deb package"*), enquanto
   `rpmtoarch` só com `.rpm`. pkg_convert lida com **os dois**
   (`.deb`, `.rpm`) da mesma GUI com resultados idênticos
   (verificado: mesmo hash binário, mesmo tamanho para deb/rpm).
2. **Sem banco de dados de 1,1 GB.** `debtap` baixa uma lista de
   pacotes Debian/Ubuntu (≈1,1 GB de cache, com root). pkg_convert usa
   `pkgfile`, que consulta seu banco **local** do Arch — sem download
   grande, sem etapa de atualização separada.
3. **Detecção de dependências mais completa.** Em testes com
   diferentes programas fornecidos tanto em `.deb` ou `.rpm`,
   pkg_convert resolveu **11** bibliotecas
   (gtk3, webkit2gtk-4.1, cairo, pango, glib2, libsoup, zlib, glibc,
   gcc-libs, gdk-pixbuf2, libx11) contra **4** do debtap.
4. **C++/Qt6 nativo, sem runtime Python.** `debtap` é bash + Python
   (chega a chamar `namcap` via Python). pkg_convert compila para um
   único ELF de ~130 KB — sem interpretador, sem dependência Python.
5. **GUI Qt6 integrada com 6 idiomas** (DE/EN/FR/ES/TR/PT), claro/
   escuro, histórico, log copiável.
6. **Sem AUR.** `debtap`/`rpmtoarch` vêm do AUR. pkg_convert é
   construído do seu código-fonte via `makepkg -si`.

### Limitações honestas

- Ainda sem script `.INSTALL` para o cache de ícones (debtap gera um
  com `gtk-update-icon-cache` + `update-desktop-database`).
- `makepkg` remove símbolos do binário por padrão (≈12 % menor que a
  cópia 1:1 do debtap) ; funcionalmente idêntico.
- `pkgname` carrega sufixo de versão (ex. `program-1.99.16`).
- `pkgfile` depende de um banco local atualizado ; execute `pacman -Sy`
  se as correspondências parecerem obsoletas.

## Compilar & Instalar (do código-fonte, sem AUR)

```bash
git clone https://github.com/hyalcin70/pkg_convert
cd pkg_convert
makepkg -si
```

Depois **Paket Converter** aparece no menu KDE
(categoria: Utilitário / Gerenciamento de Pacotes).

## Uso

1. **Navegar** → selecionar um arquivo `.deb` ou `.rpm`
2. **Construir pacote** (ou "Pacote + Fontes")
3. **Instalar pacote** → inserir senha, pronto

## Notas

- Alguns projetos dividem jogos em programa + pacote `-data`. Se
  faltarem gráficos/som, converta também o pacote de dados.
- Bibliotecas existentes apenas no **AUR** não são instaladas
  automaticamente — a ferramenta avisa.

## Dependências

`qt6-base` (fornece `qmake6`), `pacman`, `file`, `binutils`, `cpio`,
`libarchive`
