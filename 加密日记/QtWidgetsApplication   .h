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
    QString text_dz = NULL;//�����ļ���ַ�ַ���
    bool text_dz_b = 1;//������ʾ�����ļ���ַ�ַ����Ƿ�Ϊ��
    QString mm_dz = NULL;//�����ļ���ַ�ַ���
    bool mm_dz_b = 1;//������ʾ�����ļ���ַ�ַ����Ƿ�Ϊ��
    QString jg_dz = NULL;//����ļ���ַ�ַ���
    bool jg_dz_b = 1;//������ʾ����ļ���ַ�ַ����Ƿ�Ϊ��
    Ui::QtWidgetsApplicationClass ui;
private slots:
    
    void xz_sr_dz() {//������ʾ���Ի�������ļ��ĵ�ַ
        text_dz = QFileDialog::getOpenFileName(NULL, QString::fromLocal8Bit("ѡ�������ļ���ַ"), ".", "*.*");//������ʾ��
        if (text_dz.isEmpty()) {//�ж������ַ�Ƿ�Ϊ��
            return;
        }
        text_dz_b = 0;//�������ļ���ַ�ַ������Ϊ�ǿ�
        ui.lineEdit->setText(text_dz);//���ļ���ַ��ʾ��������������
    }
    void xz_mm_dz() {//������ʾ���Ի�������ļ��ĵ�ַ
        mm_dz = QFileDialog::getOpenFileName(NULL, QString::fromLocal8Bit("ѡ�������ļ���ַ"), ".", "*.*");//ѡ�������ļ���ַ
        if (mm_dz.isEmpty()) {
            return;
        }
        mm_dz_b = 0;
        ui.lineEdit_3->setText(mm_dz);
    }
    void xz_jg_dz() {//������ʾ���Ի������ļ��ĵ�ַ
        jg_dz = QFileDialog::getOpenFileName(NULL, QString::fromLocal8Bit("ѡ������ļ���ַ"), ".", "*.*");//ѡ������ļ���ַ
        if (jg_dz.isEmpty()) {
            return;
        }
        jg_dz_b = 0;
        ui.lineEdit_2->setText(jg_dz);
    }
    void jm() {//����
        int size_ = sizeof(int);//��ȡint�ĳ��ȣ���ΪҪ֧�ּ��ܶ������ļ�
        if (text_dz_b) {//�ж������ļ���ַ�Ƿ�Ϊ��
            text_dz = ui.lineEdit->text();//�������ļ���ַΪ�����ȡ������еĵ�ַ
        }
        QString mm;//�����洢������ַ���
        size_t  mm_hs;//�����������Ĺ�ϣֵ
        QFile sr_file(text_dz);//����QFile�����������������ļ���ַ
        if (!sr_file.exists()) {//�ж������ļ��Ƿ���ڣ����������򵯳���ʾ���˳�
            QMessageBox::information(this, QString::fromLocal8Bit("��ʾ��Ϣ"), QString::fromLocal8Bit("�����ļ�������"));//������ʾ��
            return;
        }
        sr_file.open(QIODevice::ReadOnly);//�������ļ�
        QDataStream sr_Stream(&sr_file);//�Զ����ƴ������ļ�
        sr_Stream.setByteOrder(QDataStream::LittleEndian);//�����ֽ�˳��ΪС���ֽ���
        QFileInfo SR_LEN(text_dz);//����QFileInfo��������ֻ�Ƕ�ȡ�������ļ������õ�
        if (jg_dz_b) {//�ж������ַ�Ƿ�Ϊ��
            jg_dz = ui.lineEdit_2->text();//������ļ���ַΪ�����ȡ������еĵ�ַ
        }
        QFile jg(jg_dz);//����QFile����������������ļ���ַ
        jg.open(QIODevice::WriteOnly);//������ļ�
        QDataStream jg_Stream(&jg);//�Զ����ƴ�����ļ�
        jg_Stream.setByteOrder(QDataStream::LittleEndian);//�����ֽ�˳��ΪС���ֽ���
        if(ui.radioButton->isChecked()){//��ȡ��ť״̬��ȷ��ѡ����Ƿ�Ϊֱ����������
            mm = ui.textEdit_2->document()->toPlainText();//��������������
        }
        else {//����������ļ��ж�ȡ����
            if (mm_dz_b) {//�ж������ļ���ַ�Ƿ�Ϊ��
                mm_dz = ui.lineEdit_3->text();//��Ϊ�����������ȡ�����ļ���ַ
            }
            QFile mm_file(mm_dz);//����QFile���������������ļ���ַ
            if (!mm_file.exists()) {//���ļ��������򵯳���ʾ���˳�
                QMessageBox::information(this, QString::fromLocal8Bit("��ʾ��Ϣ"), QString::fromLocal8Bit("�����ļ�������"));
                return;
            }
            mm_file.open(QIODevice::ReadOnly);//�������ļ�
            mm = mm_file.readAll();//��������
        }
        int mm_dq_wz = 0;//�������ֻ��Ϊ������ַ��ض�ȡ����
        int mm_len = mm.length();//��ȡ���볤��
        std::cout << mm_len << std::endl;
        QString mm_a_bit;//����������ÿ������ת��ϣ�������ַ���
        if (mm_len > 18) {//�����볤�ȴ���ʮ��λ�������ֳ�ÿ��18λ��С��ȡ��ϣֵ����ΪC++�ṩ�Ĺ�ϣ�������Ϊ�̶���ʮ��λ�����Էֶγ��ȶ������׹�ϣ��ײ���������˷�
            for (int i = 0; i < 18; i++) {
                mm_a_bit += mm[mm_dq_wz];//��������ַ����ַ�һ��һ���ص��뵽mm_a_bit
                mm_dq_wz++;//�������ƶ�һ��
                mm_len--;//����ʣ�೤�ȼ�һ
            }
            mm_hs = std::hash<QString>()(mm_a_bit);//����һС�λ��ɹ�ϣֵ
            mm_a_bit = { 0 };//����
        }
        else {
            mm_hs = std::hash<QString>()(mm);//�����Ȳ���18λ��ֱ��ת��Ϊ��ϣֵ
        }
        for (int i = 0; i < SR_LEN.size(); i += sizeof(int)) {//�������ļ�����һ��
            if (SR_LEN.size() - i < sizeof(int)) {//����Ϊ���ļ�����ȫ��ȡд�ģ�����������ʱ����ļ�һ���Զ���
                size_ = SR_LEN.size() - i;
            }
            long long* a = new long long;
            sr_Stream.readRawData((char*)a, size_);//��int�ĳ��ȶ�ȡ�ļ�
            long long long_a = long long(*a) + long long(mm_hs % 10);//�����㷨������ȡ��ϣ֮���ÿһλ����ԭ���ݵ�ÿһλ�����Ϊ���ܺ������
            jg_Stream.writeRawData((char*)&(long_a), size_ + 1);//д�룬��д�볤�Ȼ��1����Ϊ����1�����
            mm_hs = mm_hs / 10;//д��������ÿһλ�ֿ��Ķ�֪�������ڸ�ʲô
            if (mm_hs <= 0) {//������ǵ������ϣ��������»�ȡ�����ϣֵ��������һ�����Ͳ��ظ�дע����
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
        text_dz_b = 1;//���ù�����ȫ����ʼ��
        mm_dz_b = 1;
        jg_dz_b = 1;
        mm_hs = 0;
        jg.close();//�رղ�д��������ļ�
        QMessageBox::information(this, QString::fromLocal8Bit("��ʾ��Ϣ"), QString::fromLocal8Bit("���ܳɹ�"));//������ʾ��
    };
    //����Ĵ��������һ����ֻ��һ���Ӽ��ŵ�����
    void fjm() {
        int size_ = sizeof(int)+1;
        if (text_dz_b) {
            text_dz = ui.lineEdit->text();
        }
        QString mm;
        size_t  mm_hs;
        QFile sr_file(text_dz);//�����ļ�
        if (!sr_file.exists()) {
            QMessageBox::information(this, QString::fromLocal8Bit("��ʾ��Ϣ"), QString::fromLocal8Bit("�����ļ�������"));
            return;
        }
        sr_file.open(QIODevice::ReadOnly);
        QDataStream sr_Stream(&sr_file);
        sr_Stream.setByteOrder(QDataStream::LittleEndian);
        QFileInfo SR_LEN(text_dz);
        if (jg_dz_b) {
            jg_dz = ui.lineEdit_2->text();
        }
        QFile jg(jg_dz);//����ļ�
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
                QMessageBox::information(this, QString::fromLocal8Bit("��ʾ��Ϣ"), QString::fromLocal8Bit("�����ļ�������"));
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
            long long long_a = long long(*a) - long long(mm_hs % 10);//��������ļ��Ų�ͬ
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
        QMessageBox::information(this, QString::fromLocal8Bit("��ʾ��Ϣ"), QString::fromLocal8Bit("���ܳɹ�"));
    };
};
