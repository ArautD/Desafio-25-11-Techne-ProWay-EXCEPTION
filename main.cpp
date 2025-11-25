#include <iostream>
#include <cmath>
#include <stdexcept>
#include <locale>
using namespace std;

double calculoRaiz(double a, double b, double c){
    if (a==0){
        throw invalid_argument("A equação não e do segundo grau!");
    }

    double delta = b*b - 4*a*c;

    if (delta < 0){
        throw runtime_error("A equação não possui raizes reais!");
    }

    if (delta == 0){
        return -b / (2*a);
    }

    return NAN; //o NAN é usado para indicar que há as 2 raízes;
}

int main(){
    int opcao;
    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001 > nul");
    system("cls");

    do{
        system("cls");
        cout << "\n==============================================\n" << endl;
        cout << "TRATAMENTO DE EXCEPTIONS" << endl;
        cout << "\n==============================================\n" << endl;

        cout << "Selecione uma das opções e aproveite :) \n";
        cout << "1) Iniciar\n";
        cout << "0) Sair\n";
        cout << "opção selecionada: ";
        cin >> opcao;
        cin.ignore();
    
        switch (opcao){
            case 1:
                double a, b, c;
                system("cls");
                cout << "Digite o valor de a: ";
                cin >> a;
                cout << "Digite o valor de b: ";
                cin >> b;
                cout << "Digite o valor de c: ";
                cin >> c;

                try{
                    double resultado = calculoRaiz(a, b, c);

                    if(isnan(resultado)) {
                        double delta = b*b -4*a*c;
                        double x1 = (-b + sqrt(delta)) / (2*a);
                        double x2 = (-b - sqrt(delta)) / (2*a);
                        cout << "A equação possui duas raizes reais: " << x1 << " e " << x2 << endl;
                        system("pause");
                    }else{
                        cout << "A equação possui uma raiz real: " << resultado << endl;
                        system("pause");
                    }
                }
                catch (const invalid_argument& e){
                    cout << "Erro " << e.what() << endl;
                    cout << ">> Tente novamente "<< endl;
                    system("pause");
                }
                catch (const runtime_error& e){
                    cout << "Erro " << e.what() << endl;
                    cout << ">> Tente novamente "<< endl;
                    system("pause");
                }
                catch (...){
                    cout << "Erro Desconhecido ???" << endl;
                    cout << ">> Tente novamente "<< endl;
                    system("pause");
                }

                break;
            case 0:
                system("cls");
                cout << "Saindo..." << endl;
                break;

            default:
                cout << "Opção Inválida!" << endl;
        }
        
        
    } while (opcao != 0);

    return 0;
}