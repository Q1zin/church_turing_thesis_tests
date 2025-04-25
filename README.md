
# Тезис Черча (тестовая система)

Задания: [Клац](https://docs.google.com/document/d/17dpjFF7Hvy8LJ8nsuiGhaohUHbUnEs_erUZxf5Vn_nU/edit?usp=sharing)

## Структура проекта
```
.
├── Машина_Тьюринга
│   ├── machine_turing.c
│   ├── machine_turing.h
│   └── test_turing_machine.c
├── Продвижение_констант
│   ├── constant_propagation.c
│   ├── constant_propagation.h
│   └── test_constant_propagation.c
└── README.md
```

## Как собрать и запустить тесты
### Машина Тьюринга
```bash
cd Машина_Тьюринга
gcc machine_turing.c test_turing_machine.c -o test_tm
./test_tm
```

### Продвижение Констант
```bash
cd Продвижение_констант
gcc constant_propagation.c test_constant_propagation.c -o test_cp
./test_cp
```

## Формат решения:
В качестве решения исходные файлы программы, написанной на языке Си (machine_turing.c или constant_propagation.c).


## Как сдать решение:
Отправьте описанные выше файлы в телеграм [@Q1zin](https://t.me/Q1zin).
Не забудьте указать название команды и название задачи.

