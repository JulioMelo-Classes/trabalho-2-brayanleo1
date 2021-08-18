## Para compilar

Com cmake:
```console
mkdir build
cd build
cmake ..
cmake --build .
```

## Para executar
Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER dentro da pasta build no linux:
```console
./Debug/concordo
```

Ou dessa forma no windows:
```console
.\Debug\concordo.exe
```

## Para executar com os testes
<!--não foram documentados o que cada teste faz, mas é possível inferir pelos nomes dos arquivos então irei considerar-->
Ou pode executar o sistema redirecionando algum arquivo como entrada padrão no linux:
```console
./Debug/concordo < ../data/testesDeUsuario.txt
```

Ou dessa forma no windows:
```console
Get-Content ..\data\testesDeMensagens.txt | .\Debug\concordo.exe
```

## Limitações ou funcionalidades não implementadas no programa

O programa não grava os objetos criados durante a sessão, ou seja, assim que a execução do programa parar, tudo feito naquela sessão será perdido.