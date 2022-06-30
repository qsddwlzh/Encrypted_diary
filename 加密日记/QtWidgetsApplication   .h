#pragma once

#include <iostream>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication.h"
#include <string>
#include <functional>
#include <QFileDevice>
#include <QTemporaryFile>
#include <QMessageBox>
#include <QFileInfo>
#include <iostream>
#include <QFileDialog>
class QtWidgetsApplication : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget *parent = Q_NULLPTR);

private:
    QString text_dz = NULL;//输入文件地址字符串
    bool text_dz_b = 1;//用来表示输入文件地址字符串是否为空
    QString mm_dz = NULL;//密码文件地址字符串
    bool mm_dz_b = 1;//用来表示密码文件地址字符串是否为空
    QString jg_dz = NULL;//输出文件地址字符串
    bool jg_dz_b = 1;//用来表示输出文件地址字符串是否为空
    Ui::QtWidgetsApplicationClass ui;
private slots:
    
    void xz_sr_dz() {//弹出提示框以获得输入文件的地址
        text_dz = QFileDialog::getOpenFileName(NULL, QString::fromLocal8Bit("选择输入文件地址"), ".", "*.*");//弹出提示框
        if (text_dz.isEmpty()) {//判断输入地址是否为空
            return;
        }
        text_dz_b = 0;//把输入文件地址字符串标记为非空
        ui.lineEdit->setText(text_dz);//把文件地址显示到输入框里，以提醒
    }
    void xz_mm_dz() {//弹出提示框以获得密码文件的地址
        mm_dz = QFileDialog::getOpenFileName(NULL, QString::fromLocal8Bit("选择密码文件地址"), ".", "*.*");//选择密码文件地址
        if (mm_dz.isEmpty()) {
            return;
        }
        mm_dz_b = 0;
        ui.lineEdit_3->setText(mm_dz);
    }
    void xz_jg_dz() {//弹出提示框以获得输出文件的地址
        jg_dz = QFileDialog::getOpenFileName(NULL, QString::fromLocal8Bit("选择输出文件地址"), ".", "*.*");//选择输出文件地址
        if (jg_dz.isEmpty()) {
            return;
        }
        jg_dz_b = 0;
        ui.lineEdit_2->setText(jg_dz);
    }
    void jm() {//加密
        int size_ = sizeof(int);//获取int的长度，因为要支持加密二进制文件
        if (text_dz_b) {//判断输入文件地址是否为空
            text_dz = ui.lineEdit->text();//若输入文件地址为空则读取输入框中的地址
        }
        QString mm;//用来存储密码的字符串
        size_t  mm_hs;//用来存放密码的哈希值
        QFile sr_file(text_dz);//创建QFile变量，并输入输入文件地址
        if (!sr_file.exists()) {//判断输入文件是否存在，若不存在则弹出提示框并退出
            QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("输入文件不存在"));//生成提示框
            return;
        }
        sr_file.open(QIODevice::ReadOnly);//打开输入文件
        QDataStream sr_Stream(&sr_file);//以二进制打开输入文件
        sr_Stream.setByteOrder(QDataStream::LittleEndian);//设置字节顺序为小端字节序
        QFileInfo SR_LEN(text_dz);//创建QFileInfo变量，这只是读取二进制文件长度用的
        if (jg_dz_b) {//判断输出地址是否为空
            jg_dz = ui.lineEdit_2->text();//若输出文件地址为空则读取输入框中的地址
        }
        QFile jg(jg_dz);//创建QFile变量，并输入输出文件地址
        jg.open(QIODevice::WriteOnly);//打开输出文件
        QDataStream jg_Stream(&jg);//以二进制打开输出文件
        jg_Stream.setByteOrder(QDataStream::LittleEndian);//设置字节顺序为小端字节序
        if(ui.radioButton->isChecked()){//读取按钮状态以确定选择的是否为直接输入密码
            mm = ui.textEdit_2->document()->toPlainText();//从输入框读入密码
        }
        else {//否则从密码文件中读取密码
            if (mm_dz_b) {//判断密码文件地址是否为空
                mm_dz = ui.lineEdit_3->text();//若为空则从输入框读取密码文件地址
            }
            QFile mm_file(mm_dz);//创建QFile变量并输入密码文件地址
            if (!mm_file.exists()) {//若文件不存在则弹出提示框并退出
                QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("密码文件不存在"));
                return;
            }
            mm_file.open(QIODevice::ReadOnly);//打开密码文件
            mm = mm_file.readAll();//读入密码
        }
        int mm_dq_wz = 0;//这个变量只是为了逐个字符地读取密码
        int mm_len = mm.length();//获取密码长度
        std::cout << mm_len << std::endl;
        QString mm_a_bit;//这是用来存每次密码转哈希的密码字符串
        if (mm_len > 18) {//若密码长度大于十八位则把密码分成每份18位的小段取哈希值，因为C++提供的哈希函数输出为固定的十八位，所以分段长度多了容易哈希碰撞，少了又浪费
            for (int i = 0; i < 18; i++) {
                mm_a_bit += mm[mm_dq_wz];//把密码的字符的字符一个一个地导入到mm_a_bit
                mm_dq_wz++;//光标向后移动一个
                mm_len--;//密码剩余长度减一
            }
            mm_hs = std::hash<QString>()(mm_a_bit);//把这一小段换成哈希值
            mm_a_bit = { 0 };//归零
        }
        else {
            mm_hs = std::hash<QString>()(mm);//若长度不到18位则直接转换为哈希值
        }
        for (int i = 0; i < SR_LEN.size(); i += sizeof(int)) {//把输入文件遍历一遍
            if (SR_LEN.size() - i < sizeof(int)) {//这是为了文件被完全读取写的，可以在最后的时候把文件一次性读完
                size_ = SR_LEN.size() - i;
            }
            long long* a = new long long;
            sr_Stream.readRawData((char*)a, size_);//以int的长度读取文件
            long long long_a = long long(*a) + long long(mm_hs % 10);//加密算法：密码取哈希之后的每一位与与原数据的每一位相加作为加密后的数据
            jg_Stream.writeRawData((char*)&(long_a), size_ + 1);//写入，但写入长度会加1，因为不加1会溢出
            mm_hs = mm_hs / 10;//写过把数的每一位分开的都知道这是在干什么
            if (mm_hs <= 0) {//下面就是当密码哈希用完后重新获取密码哈希值，和上面一样，就不重复写注释了
                if (mm_len > 18) {
                    for (int i = 0; i < 18; i++) {
                        mm_a_bit += mm[mm_dq_wz];
                        mm_dq_wz++;
                        mm_len--;
                        if (mm_dq_wz >= mm_len) {
                            break;
                        }
                    }
                    mm_hs = std::hash<size_t>()(mm_a_bit.toInt()+mm_hs%1000);
                    mm_a_bit = { 0 };
                }
                else {
                    mm_hs = std::hash<size_t>()(mm_hs);
                }
            }
        }
        text_dz_b = 1;//把用过的量全部初始化
        mm_dz_b = 1;
        jg_dz_b = 1;
        mm_hs = 0;
        jg.close();//关闭并写入二进制文件
        QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("加密成功"));//弹出提示框
    };
    //下面的代码和上面一样，只是一个加减号的区别。
    void fjm() {
        int size_ = sizeof(int)+1;
        if (text_dz_b) {
            text_dz = ui.lineEdit->text();
        }
        QString mm;
        size_t  mm_hs;
        QFile sr_file(text_dz);//输入文件
        if (!sr_file.exists()) {
            QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("输入文件不存在"));
            return;
        }
        sr_file.open(QIODevice::ReadOnly);
        QDataStream sr_Stream(&sr_file);
        sr_Stream.setByteOrder(QDataStream::LittleEndian);
        QFileInfo SR_LEN(text_dz);
        if (jg_dz_b) {
            jg_dz = ui.lineEdit_2->text();
        }
        QFile jg(jg_dz);//输出文件
        jg.open(QIODevice::WriteOnly);
        QDataStream jg_Stream(&jg);
        jg_Stream.setByteOrder(QDataStream::LittleEndian);
        if (ui.radioButton->isChecked()) {
            mm = ui.textEdit_2->document()->toPlainText();
        }
        else {
            if (mm_dz_b) {
                mm_dz = ui.lineEdit_3->text();
            }
            QFile mm_file(mm_dz);
            if (!mm_file.exists()) {
                QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("密码文件不存在"));
                return;
            }
            mm_file.open(QIODevice::ReadOnly);
            mm = mm_file.readAll();
            
        }
        int mm_dq_wz = 0;
        int mm_len = mm.length();
        std::cout << mm_len << std::endl;
        QString mm_a_bit;
        if (mm_len > 18) {
            for (int i = 0; i < 18; i++) {
                mm_a_bit += mm[mm_dq_wz];
                mm_dq_wz++;
                mm_len--;
            }
            mm_hs = std::hash<QString>()(mm_a_bit);
            mm_a_bit = { 0 };
        }
        else {
            mm_hs = std::hash<QString>()(mm);
        }
        for (int i = 0; i < SR_LEN.size(); i+= sizeof(int)+1) {
            if (SR_LEN.size() - i < sizeof(int)+1) {
                size_ = SR_LEN.size() - i;
            }
            long long* a = new long long;
            sr_Stream.readRawData((char*)a, size_);
            long long long_a = long long(*a) - long long(mm_hs % 10);//就是这里的减号不同
            jg_Stream.writeRawData((char*)&(long_a), size_-1);
            mm_hs = mm_hs / 10;
            if (mm_hs <= 0) {
                if (mm_len > 18) {
                    for (int i = 0; i < 18; i++) {
                        mm_a_bit += mm[mm_dq_wz];
                        mm_dq_wz++;
                        mm_len--;
                        if (mm_dq_wz >= mm_len) {
                            break;
                        }
                    }
                    mm_hs = std::hash<size_t>()(mm_a_bit.toInt() + mm_hs % 1000);
                    mm_a_bit = { 0 };
                }
                else {
                    mm_hs = std::hash<size_t>()(mm_hs);
                }
            }
        }
        text_dz_b = 1;
        mm_dz_b = 1;
        jg_dz_b = 1;
        mm_hs = 0;
        jg.close();
        QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("解密成功"));
    };
};
