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
- **Caminho do binário** : Os executáveis dos programas/jogos são movidos para `/usr/bin/` para ficarem no `PATH` do Arch.
- **Aviso** para pacotes de dados puros (sem executável)
- **Popup de dica** na instalação se faltarem pacotes de dados
  adicionais (`-data`, `-common`)
- **Log copiável**, histórico de instalação persistente
- **Alternador Claro/Escuro** (padrão: claro)

## Por que pkg_convert ?

pkg_convert segue uma abordagem própria para formatos de pacotes
externos, voltada a usuários que querem converter diretamente no Arch
sem depender de helpers do AUR nessa etapa.

1. **Uma ferramenta para ambos os formatos externos.** Em vez de
   combinar várias opções de formato único, pkg_convert trabalha com
   **`.deb` e `.rpm`** na mesma GUI e com layout de pacote coerente.
2. **Banco de dados local do Arch:** As bibliotecas são resolvidas
     com `readelf` + `pkgfile` contra a sync DB local — sem downloads
     grandes nem serviço de atualização separado.
3. **Dependências por soname real.** Identificadas com `readelf` +
   `pkgfile`, não por tabelas de nomes fixas de outras distribuições.
4. **C++/Qt6 nativo, sem intérprete em runtime.** Um único binário,
   sem Python/Bash durante a execução.
5. **GUI Qt6 integrada** com multilíngue, claro/escuro, histórico de
   instalação e log copiável.
6. **Sem helper do AUR.** Build e teste a partir do source via
   `makepkg -si`.

### Limitações honestas

- Ainda sem script `.INSTALL` para atualização automática do cache de
  ícones; os ícones do menu podem exigir `gtk-update-icon-cache` +
  `update-desktop-database` manual.
- `makepkg` remove símbolos por padrão; funcionalmente igual a uma
  cópia 1:1, só que menor.
- `pkgname` carrega um sufixo de versão, ex. `program-1.99.16`.
- `pkgfile` depende de uma sync DB local atualizada; execute `pacman -Sy`
  se as correspondências parecerem desatualizadas.

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
