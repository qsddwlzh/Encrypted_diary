#pragma once


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
    QString text_dz = NULL;//输入文件地址
    bool text_dz_b = 0;
    QString mm_dz = NULL;//密码文件地址
    bool mm_dz_b = 0;
    QString jg_dz = NULL;//输出文件地址
    bool jg_dz_b = 0;
    Ui::QtWidgetsApplicationClass ui;
private slots:
    
    void xz_sr_dz() {
        text_dz = QFileDialog::getOpenFileName(NULL, QString::fromLocal8Bit("选择输入文件地址"), ".", "*.*");//选择输入文件地址
        if (text_dz.isEmpty()) {
            return;
        }
        text_dz_b = 0;
        ui.lineEdit->setText(text_dz);
    }
    void xz_mm_dz() {
        mm_dz = QFileDialog::getOpenFileName(NULL, QString::fromLocal8Bit("选择密码文件地址"), ".", "*.*");//选择密码文件地址
        if (mm_dz.isEmpty()) {
            return;
        }
        mm_dz_b = 0;
        ui.lineEdit_3->setText(mm_dz);
    }
    void xz_jg_dz() {
        jg_dz = QFileDialog::getOpenFileName(NULL, QString::fromLocal8Bit("选择输出文件地址"), ".", "*.*");//选择输出文件地址
        if (jg_dz.isEmpty()) {
            return;
        }
        jg_dz_b = 0;
        ui.lineEdit_2->setText(jg_dz);
    }
    void jm() {
        int size_ = sizeof(int);
        if (!text_dz_b) {
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
        quint16 text;
        if (!jg_dz_b) {
            jg_dz = ui.lineEdit_2->text();
        }
        QFile jg(jg_dz);//输出文件
        jg.open(QIODevice::WriteOnly);
        QDataStream jg_Stream(&jg);
        jg_Stream.setByteOrder(QDataStream::LittleEndian);
        QByteArray jg_byte;
        QString jg_QString;
        if(ui.radioButton->isChecked()){
            mm = ui.textEdit_2->document()->toPlainText();
            int mm_dq_wz = 0;
            int mm_len = mm.length();
            QString mm_a_bit;
            if (mm_len > 18) {
                for (int i = 0; i < 18; i++) {
                    mm_a_bit += mm[mm_dq_wz];
                    mm_dq_wz++;
                    mm_len--;
                    if (mm_dq_wz >= mm_len) {
                        break;
                    }
                }
                mm_hs = std::hash<std::string>()(mm_a_bit.toStdString());
                mm_a_bit = { 0 };
            }
            else {
                mm_hs = std::hash<std::string>()(mm.toStdString());
            }
            if (mm_len > 18) {
                mm_len -= 18;
            }
            for (int i = 0; i < SR_LEN.size(); i+=sizeof(int)) {
                if (SR_LEN.size()-i < sizeof(int)) {
                    size_ = SR_LEN.size() - i;
                }
                long long* a = new long long;
                sr_Stream.readRawData((char*)a,size_);
                long long long_a = long long(*a) + long long(mm_hs % 10);
                jg_Stream.writeRawData((char*)&(long_a), size_);
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
                        mm_hs = std::hash<std::string>()(mm_a_bit.toStdString());
                        mm_a_bit = { 0 };
                    }
                    else {
                        mm_hs = std::hash<std::string>()(mm.toStdString());
                    }
                }
            }
        }
        else {
            if (!mm_dz_b) {
                mm_dz = ui.lineEdit_3->text();
            }
            QFile mm_file(mm_dz);
            if (!mm_file.exists()) {
                QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("密码文件不存在"));
                return;
            }
            mm_file.open(QIODevice::ReadOnly);
            mm = mm_file.readAll();
            int mm_dq_wz = 0;
            int mm_len = mm.length();
            QString mm_a_bit;
            if (mm_len > 18) {
                for (int i = 0; i < 18; i++) {
                    mm_a_bit += mm[mm_dq_wz];
                    mm_dq_wz++;
                    mm_len--;
                    if (mm_dq_wz >= mm_len) {
                        break;
                    }
                }
                mm_hs = std::hash<std::string>()(mm_a_bit.toStdString());
                mm_a_bit = { 0 };
            }
            else {
                mm_hs = std::hash<std::string>()(mm.toStdString());
            }
            for (int i = 0; i < SR_LEN.size(); i+= sizeof(int)) {
                if (SR_LEN.size() - i < sizeof(int)) {
                    size_ = SR_LEN.size() - i;
                }
                long long* a = new long long;
                sr_Stream.readRawData((char*)a, size_);
                long long long_a = long long(*a) + long long(mm_hs % 10);
                jg_Stream.writeRawData((char*)&(long_a), size_);
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
                        mm_hs = std::hash<std::string>()(mm_a_bit.toStdString());
                        mm_a_bit = { 0 };
                    }
                    else {
                        mm_hs = std::hash<std::string>()(mm.toStdString());
                    }
                }
            }
        }
        text_dz_b = 0;
        mm_dz_b = 0;
        jg_dz_b = 0;
        jg.close();
        QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("加密成功"));
    };
    void fjm() {
        int size_ = sizeof(int);
        if (!text_dz_b) {
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
        quint16 text;
        if (!jg_dz_b) {
            jg_dz = ui.lineEdit_2->text();
        }
        QFile jg(jg_dz);//输出文件
        jg.open(QIODevice::WriteOnly);
        QDataStream jg_Stream(&jg);
        jg_Stream.setByteOrder(QDataStream::LittleEndian);
        QByteArray jg_byte;
        QString jg_QString;
        if (ui.radioButton->isChecked()) {
            mm = ui.textEdit_2->document()->toPlainText();
            int mm_dq_wz = 0;
            int mm_len = mm.length();
            QString mm_a_bit;
            if (mm_len > 18) {
                for (int i = 0; i < 18; i++) {
                    mm_a_bit += mm[mm_dq_wz];
                    mm_dq_wz++;
                    mm_len--;
                    if (mm_dq_wz >= mm_len) {
                        break;
                    }
                }
                mm_hs = std::hash<std::string>()(mm_a_bit.toStdString());
                mm_a_bit = { 0 };
            }
            else {
                mm_hs = std::hash<std::string>()(mm.toStdString());
            }
            for (int i = 0; i < SR_LEN.size(); i+= sizeof(int)) {
                if (SR_LEN.size() - i < sizeof(int)) {
                    size_ = SR_LEN.size() - i;
                }
                long long* a = new long long;
                sr_Stream.readRawData((char*)a, size_);
                long long long_a = long long(*a) - long long(mm_hs % 10);
                jg_Stream.writeRawData((char*)&(long_a), size_);
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
                        mm_hs = std::hash<std::string>()(mm_a_bit.toStdString());
                        mm_a_bit = { 0 };
                    }
                    else {
                        mm_hs = std::hash<std::string>()(mm.toStdString());
                    }
                }
            }
        }
        else {
            if (!mm_dz_b) {
                mm_dz = ui.lineEdit_3->text();
            }
            QFile mm_file(mm_dz);
            if (!mm_file.exists()) {
                QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("密码文件不存在"));
                return;
            }
            mm_file.open(QIODevice::ReadOnly);
            mm = mm_file.readAll();
            int mm_dq_wz = 0;
            int mm_len = mm.length();
            QString mm_a_bit;
            if (mm_len > 18) {
                for (int i = 0; i < 18; i++) {
                    mm_a_bit += mm[mm_dq_wz];
                    mm_dq_wz++;
                    mm_len--;
                    if (mm_dq_wz >= mm_len) {
                        break;
                    }
                }
                mm_hs = std::hash<std::string>()(mm_a_bit.toStdString());
                mm_a_bit = { 0 };
            }
            else {
                mm_hs = std::hash<std::string>()(mm.toStdString());
            }
            for (int i = 0; i < SR_LEN.size(); i+= sizeof(int)) {
                if (SR_LEN.size() - i < sizeof(int)) {
                    size_ = SR_LEN.size() - i;
                }
                long long* a = new long long;
                sr_Stream.readRawData((char*)a, size_);
                long long long_a = long long(*a) - long long(mm_hs % 10);
                jg_Stream.writeRawData((char*)&(long_a), size_);
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
                        mm_hs = std::hash<std::string>()(mm_a_bit.toStdString());
                        mm_a_bit = { 0 };
                    }
                    else {
                        mm_hs = std::hash<std::string>()(mm.toStdString());
                    }
                }
            }
        }
        text_dz_b = 0;
        mm_dz_b = 0;
        jg_dz_b = 0;
        jg.close();
        QMessageBox::information(this, QString::fromLocal8Bit("提示消息"), QString::fromLocal8Bit("解密成功"));
    };
};
