#include "mainwindow.h"
#include "./ui_mainwindow.h"

double first_number;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digit_numbers()));

    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_remainder, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_numbers()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    QString str;
    double numbers;
    if(ui->result->text().contains(".") && button->text() == "0"){
        str = ui->result->text() + "0";
    } else {
        numbers = (ui->result->text()+button->text()).toDouble();
        str = QString::number(numbers,'g',10 );
    }

    ui->result->setText(str);
}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result->text().contains('.')))
    {
        ui->result->setText(ui->result->text() + '.');
    }
}

void MainWindow::operations()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    QString str;
    double numbers;


    if(button->text() == "+/-")
    {
        numbers = (ui->result->text()).toDouble();
        numbers = numbers * -1;
        str = QString::number(numbers,'g',15 );
        ui->result->setText(str);
    } else if (button->text() == "%") {
        numbers = (ui->result->text()).toDouble();
        numbers = numbers * 0.01;
        str = QString::number(numbers,'g',15 );
        ui->result->setText(str);
    }

}

void MainWindow::math_operations()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    first_number = ui->result->text().toDouble();

    ui->result->setText("");

    button->setChecked(true);

}

void MainWindow::on_pushButton_equal_clicked()
{
    double second_number, label_number;
    QString new_label;

    second_number = ui->result->text().toDouble();
    if(ui->pushButton_plus->isChecked())
    {
        label_number = first_number + second_number;
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()) {
        label_number = first_number - second_number;
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked()) {
        if(second_number == 0)
            {
                ui->result->setText("0");
        }
        else {
            ui->result->setText(new_label);
        }

        ui->pushButton_divide->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked()) {
        label_number = first_number * second_number;

        ui->pushButton_multiply->setChecked(false);
    }

    new_label = QString::number(label_number,'g',15 );
    ui->result->setText(new_label);

}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->result->setText("0");
    first_number = 0;
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
}

