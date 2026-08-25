# JournalLogger

### Установка зависимостей:
```bash
sudo apt install gcc g++ make doxygen
```

### Сборка:

#### Сборка библиотеки:
```bash
make library # сборка в debug mode
```
```bash
make library BUILD=release # сборка в release mode
```
### Сборка приложения:
```bash
make # сборка в debug mode
```
```bash
make BUILD=release # сборка в release моде
```
### Чистка от файлов:
```bash
make clean
```

### Запуск:

```bash
make library

make 

export LD_LIBRARY_PATH=./logger:$LD_LIBRARY_PATH # установка зависимостей для библиотеки logger

./JournalLogger <path-to-file> <low|medium|high>
```
### Генерация документации:
```bash
doxygen
```




