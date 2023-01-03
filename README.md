# Huge Binary Numbers Multiplication System

**Número da Lista**: 32<br>
**Conteúdo da Disciplina**: D&C<br>

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 18/0149687  |  Daniel Porto de Souza |

## Sobre 
Quem nunca precisou multiplicar dois números binário de 7894 dígitos, não é mesmo? O objetivo deste app simples é possibilitar essa cálculo se desprendendo dos imites de tamanho dos tipos de dados das arquiteturas e liguagens. Para isso foi aplicado a multiplicação de Karatsuba utilizando métodos de manipulação de strings. Além disso, também foi feita a multiplicação convencional para fins de comparação de desempenho.

## Screenshots
![](/assets/screenshots/dc-img01.png)
![](/assets/screenshots/dc-img02.png)
![](/assets/screenshots/dc-img03.png)

## Instalação 
**Linguagem**: C++<br>

Para rodar o projeto, é preciso estar em ambiente linux com a biblioteca gtkmm instalada, bem como as ferramentos de superte ao desenvolvimento em c++: g++, make, git...

O tutorial para instalação do gtkmm pode ser encontrado no [site da Gnome](https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/chapter-installation.html) para as diversas distribuições.

## Uso 
Para a utilização, basta clonar o repositório com:
> $ git clone https://github.com/projeto-de-algoritmos/DC-Huge-Binary-Numbers-Multiplication-System.git

Feito a clone, dentro do diretório do repositório, basta compilar o projeto com o comando:

> $ make

Para iniciar o app:

> $ make run

Serão dispostos quanto campo de input de texto. Os da esquerda são referente ao número em binário, e os da direita ao número em decimal;

Pode-se inserir um número em qualquer campo. Para converte-lo para a outra representação, basta teclar enter quando terminar de digitar o número.

Para realizar a multiplicação, basta clicar no botão "Calculate". a resposta aparecerá logo abaixo em representação binário e decimal. 

Também aparecerá o tempo decorrido na aplicação da multiplicação e qual foi o algoritmo utilizado.

## Outros 
Infelizmente, não foi possível observar a vantagem de desempenho da multiplicação de Karatsuba. isso pode se dever ao fato do algoritmo utilizar mais funções duxiliares que a multilicação normal. A manipulação de string também pode ser um gargalo, bem como as otimizaçõe realizadas pelo compilador.



