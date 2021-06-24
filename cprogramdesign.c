#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

struct student {
	char num[16];
	char name[16];
	char cla[16];
	int course1;
	int course2;
	int course3;
	int course4;
	char term[16];
};
void menu();//�˵�������������������
void rsg();//ѡ�񰴰༶����ѧ��¼��ѧ���ɼ�
void modify();//ѡ�񰴰༶����ѧ���޸�ѧ����Ϣ
void del();//ɾ��ѧ����Ϣ
void ssa();//ͳ��ѧ���ɼ������ֺܷ�ƽ���֣�������ƽ���ɼ���������
void isr();//���Բ�ѯ����ѧ���ɼ����鿴ÿ����Ŀ������ѧ������
void osr();//���ѧ���ɼ�����ѡ��༶����ȫ��
int length();//��ѯ�ṹ�����鳤��
struct student *openclose();//���ļ��������ݸ�ֵ�����飬�ر��ļ������ؽṹ��ָ��
FILE *fp;

int main() {
	menu();
	system("pause");
	return 0;
}

void menu() {
	int m, i;
	for (i = 0;; i++) {
		printf("***\t***\t***\t***\t***\t***\t***\t***\t***\t***\t***\t***\t***\t***\n");
		printf("\t\t\t\t\t***��ӭ����ѧ���ɼ�����ϵͳ***\n");
		printf("---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\n");
		printf("��ѡ�������Ŀ����\n\n");
		printf("\t\t\t1.¼��ѧ���ɼ�\t\t\t\t2.ͳ��ѧ���ɼ�\n");
		printf("\t\t\t3.��ѯѧ���ɼ�\t\t\t\t4.���ѧ���ɼ�\n");
		printf("\t\t\t5.�޸�ѧ����Ϣ\t\t\t\t6.ɾ��ѧ���ɼ�\n");
		printf("\t\t\t7.�˳���Ϣϵͳ\n\n");
		printf("---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\n");
		printf("��������ѡ�����Ŀ����:");
		scanf("%d", &m);
		switch (m) {
			case 1:
				rsg();
				system("cls");
				break;
			case 2:
				ssa();
				system("cls");
				break;
			case 3:
				isr();
				system("cls");
				break;
			case 4:
				osr();
				system("cls");
				break;
			case 5:
				modify();
				system("cls");
				break;
			case 6:
				del();
				system("cls");
				break;
			case 7:
				system("cls");
				printf("�����˳��С�����\n");
				exit(0);
			default:
				system("cls");
				printf("\t\t\t\t\t�������\n");
				menu();
		}
	}

}

//ѡ�񰴰༶����ѧ��¼��ѧ���ɼ�
void rsg() {
	struct student *pt;
	int i, m, j;
	char temp[16];
	pt = openclose();
	i = length();
	printf("\t\t\t\t1.���༶¼��\n\t\t\t\t2.��ѧ��¼��\n\t\t\t\t3.�������˵�\n");
	printf("������������������������������������������������\n");
	printf("��������ѡ�����Ŀ���֣�");
	scanf("%d", &m);
	switch (m) {
		case 1: {
			printf("������¼��༶����");
			scanf("%s", temp);
			printf("������������������������������������������������\n");
			printf("������ѧ���ɼ���Ϣ��\n");
			printf("����B20041613  ������  100  100  100  100  ��һ��");
			printf("����������ֵȫΪ0ʱ��ֹ���룩\n");
			scanf("%s %s %d %d %d %d %s", (*(pt + i)).num, (*(pt + i)).name, &(*(pt + i)).course1,
			      &(*(pt + i)).course2, &(*(pt + i)).course3, &(*(pt + i)).course4, (*(pt + i)).term);
			strcpy((*(pt + i)).cla, temp);
			while (strcmp((*(pt + i)).num, "0")) {
				i++;
				scanf("%s %s %d %d %d %d %s", (*(pt + i)).num, (*(pt + i)).name, &(*(pt + i)).course1,
				      &(*(pt + i)).course2, &(*(pt + i)).course3, &(*(pt + i)).course4, (*(pt + i)).term);
				strcpy((*(pt + i)).cla, temp);
			}
		};
		break;//���༶¼��
		case 2: {
			printf("������¼��ѧ�ڣ�");
			scanf("%s", temp);
			printf("������������������������������������������������\n");
			printf("������ѧ���ɼ���Ϣ��\n");
			printf("����B20041613  ������  B200416 100  100  100  100");
			printf("����������ֵȫΪ0ʱ��ֹ���룩\n");
			scanf("%s %s %s %d %d %d %d", (*(pt + i)).num, (*(pt + i)).name, (*(pt + i)).cla, &(*(pt + i)).course1,
			      &(*(pt + i)).course2, &(*(pt + i)).course3, &(*(pt + i)).course4);
			strcpy((*(pt + i)).term, temp);
			while (strcmp((*(pt + i)).num, "0")) {
				i++;
				scanf("%s %s %s %d %d %d %d", (*(pt + i)).num, (*(pt + i)).name, (*(pt + i)).cla, &(*(pt + i)).course1,
				      &(*(pt + i)).course2, &(*(pt + i)).course3, &(*(pt + i)).course4);
				strcpy((*(pt + i)).term, temp);
			}
		};
		break;//��ѧ��¼��
		case 3: {
			system("cls");
			menu();
			break;
		}
		break;
		default:
			system("cls");
			printf("\t\t\t\t\t�������\n");
			rsg();
			break;
	}
	if (m == 1 || m == 2) {
		fp = fopen("cp", "wb");
		for (j = 0; j < i ; j++) {
			fseek(fp, 80 * j, 0);
			fwrite((pt + j), 80, 1, fp);
		}
		fclose(fp);
		printf("¼��ɹ���");
		system("pause");
	}
}

//ѡ�񰴰༶����ѧ���޸�ѧ����Ϣ
void modify() {
	struct student *pt;
	char temp[16];
	int j, t, a, i, n;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\tû��ѧ����Ϣ��\n");
		system("pause");
		return;
	}
	printf("\t\t\t\t1.���༶�޸�\n\t\t\t\t2.��ѧ���޸�\n\t\t\t\t3.�������˵�\n");
	printf("��������Ŀ���֣�");
	scanf("%d", &n);
	switch (n) {
		case 1: {
			printf("������༶��");
			scanf("%s", temp);
			for (j = 0; j < i; j++) {
				if (strcmp((*(pt + j)).cla, temp) == 0) {
					printf("%d.", j);
					printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
					       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
				}
			}
			printf("�������޸�������");
			scanf("%d", &t);
			printf("����B20041613 ������ 100 100 100 100 ��һ��\n");
			printf("������������������������������������������������\n");
			for (j = 0; j < t; j++) {
				printf("��ѡ���޸�ѧ����ţ�");
				scanf("%d", &a);
				printf("�������޸�ѧ����Ϣ��\n");
				scanf("%s %s %d %d %d %d %s", (*(pt + a)).num, (*(pt + a)).name, &(*(pt + a)).course1, &(*(pt + a)).course2,
				      &(*(pt + a)).course3, &(*(pt + a)).course4, (*(pt + a)).term);
			}
		};
		break;//���༶�޸�
		case 2: {
			printf("������ѧ�ڣ�");
			scanf("%s", temp);
			for (j = 0; j < i; j++) {
				if (strcmp((*(pt + j)).term, temp) == 0) {
					printf("%d.", j);
					printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
					       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
				}
			}
			printf("�������޸�������");
			scanf("%d", &t);
			printf("����B20041613 ������ B200416 100 100 100 100\n");
			printf("������������������������������������������������\n");
			for (j = 0; j < t; j++) {
				printf("��ѡ���޸�ѧ����ţ�");
				scanf("%d", &a);
				printf("�������޸�ѧ����Ϣ��\n");
				scanf("%s %s %s %d %d %d %d", (*(pt + a)).num, (*(pt + a)).name, (*(pt + a)).cla, &(*(pt + a)).course1,
				      &(*(pt + a)).course2,
				      &(*(pt + a)).course3, &(*(pt + a)).course4);
			}
		};
		break;//��ѧ���޸�
		case 3: {
			menu();
		};
		break;//�������˵�
		default: {
			printf("�������");
		};
		break;
	}

	if (n == 1 || n == 2) {
		fp = fopen("cp", "wb");
		for (j = 0; j < i; j++) {
			fseek(fp, 80 * j, 0);
			fwrite((pt + j), 80, 1, fp);
		}
		fclose(fp);
		printf("�޸ĳɹ���\n");
		system("pause");
	}
}

//ɾ��ѧ����Ϣ
void del() {
	struct student *pt, data[N];
	char temp[16];
	int i, n = -1, j;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\tû��ѧ����Ϣ��\n");
		system("pause");
		return;
	}
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%s", temp);
	printf("������������������������������������������������\n");
	for (j = 0; j < i; j++) {
		if (strcmp((*(pt + j)).num, temp) == 0) {
			printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
			       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
			n = j;
			break;
		}
	}
	if (n == -1) {
		printf("û�и�ѧ����Ϣ��");
		return;
	} else {
		for (j = 0; j < i; j++) {
			if (j < n) {
				data[j] = *(pt + j);
			} else {
				data[j] = *(pt + j + 1);
			}
		}
	}
	fp = fopen("cp", "wb");
	for (j = 0; j < i - 1; j++) {
		fseek(fp, 80 * j, 0);
		fwrite((data + j), 80, 1, fp);
	}
	fclose(fp);
	printf("ɾ���ɹ���");
	system("pause");
}

//���༶ͳ��ѧ���ɼ������ֺܷ�ƽ���֣�������ƽ���ɼ���������
void ssa() {
	struct student *pt, ht[1];
	int i, j, n, k;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\tû��ѧ����Ϣ��\n");
		system("pause");
		return;
	}
	printf("\t\t\t\t1.���ֺܷ�ƽ���ֲ�����\n\t\t\t\t2.�������˵�\n������ѡ����Ŀ���֣�");
	scanf("%d", &n);
	printf("������������������������������������������������\n");
	switch (n) {
		case 1: {
			int sum[N], aver[N], temp = 0, h;
			for (j = 0; j < i; j++) {
				sum[j] = (*(pt + j)).course1 + (*(pt + j)).course2 + (*(pt + j)).course3 + (*(pt + j)).course4;
				aver[j] = sum[j] / 4;
			}
			for (j = 0; j < i; j++)
				printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\t\t%d\t%d\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
				       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term, sum[j], aver[j]);
			for (j = 0; j < i; j++) {
				temp = sum[0];
				h = 0;
				for (k = 0; k < i - j; k++) {
					if (temp > sum[k]) {
						temp = sum[k];
						h = k;
					}
					temp = sum[i - j - 1];
					sum[i - j - 1] = sum[h];
					sum[h] = temp;
					strcpy(ht[0].num, (*(pt + i - j - 1)).num);
					strcpy(ht[0].name, (*(pt + i - j - 1)).name);
					strcpy(ht[0].cla, (*(pt + i - j - 1)).cla);
					strcpy(ht[0].term, (*(pt + i - j - 1)).term);
					ht[0].course1 = (*(pt + i - j - 1)).course1;
					ht[0].course2 = (*(pt + i - j - 1)).course2;
					ht[0].course3 = (*(pt + i - j - 1)).course3;
					ht[0].course4 = (*(pt + i - j - 1)).course4;
					strcpy((*(pt + i - j - 1)).num, (*(pt + h)).num);
					strcpy((*(pt + i - j - 1)).name, (*(pt + h)).name);
					strcpy((*(pt + i - j - 1)).cla, (*(pt + h)).cla);
					strcpy((*(pt + i - j - 1)).term, (*(pt + h)).term);
					(*(pt + i - j - 1)).course1 = (*(pt + h)).course1;
					(*(pt + i - j - 1)).course2 = (*(pt + h)).course2;
					(*(pt + i - j - 1)).course3 = (*(pt + h)).course3;
					(*(pt + i - j - 1)).course4 = (*(pt + h)).course4;
					strcpy((*(pt + h)).num, ht[0].num);
					strcpy((*(pt + h)).name, ht[0].name);
					strcpy((*(pt + h)).cla, ht[0].cla);
					strcpy((*(pt + h)).term, ht[0].term);
					(*(pt + h)).course1 = ht[0].course1;
					(*(pt + h)).course2 = ht[0].course2;
					(*(pt + h)).course3 = ht[0].course3;
					(*(pt + h)).course4 = ht[0].course4;
				}
			}
		};
		break;
		case 2: {
			system("cls");
			menu();
		};
		break;
	}
	if (n == 1) {
		fp = fopen("cp", "wb");
		for (j = 0; j < i; j++) {
			fseek(fp, 80 * j, 0);
			fwrite((pt + j), 80, 1, fp);
		}
		fclose(fp);
		printf("����ɹ���\n");
		system("pause");
	}
}

//���Բ�ѯ����ѧ���ɼ����鿴ÿ����Ŀ������ѧ������
void isr() {
	struct student *pt;
	int i;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\tû��ѧ����Ϣ��\n");
		system("pause");
		return;
	}
	printf("\t\t\t\t1.��ѯѧ���ɼ�\n\t\t\t\t2.��ѯ��Ŀ������ѧ��\n\t\t\t\t3.�������˵�\n");
	int m;
	printf("������ѡ����Ŀ���֣�");
	scanf("%d", &m);
	printf("������������������������������������������������\n");
	switch (m) {
		case 1: {
			printf("\t\t\t\t1.��ѧ�Ų�ѯ\n\t\t\t\t2.��������ѯ\n\t\t\t\t3.������һ��\n");
			printf("������ѡ����Ŀ���֣�");
			scanf("%d", &m);
			switch (m) {
				case 1: {
					char a[16];
					int j;
					printf("������ѧ�ţ�");
					scanf("%s", a);
					for (j = 0; j < i; j++) {
						if (strcmp((*(pt + j)).num, a) == 0)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
							       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
					}
				};
				break;//��ѧ�Ų�ѯ
				case 2: {
					char a[16];
					int j;
					printf("������������");
					scanf("%s", a);
					for (j = 0; j < i; j++) {
						if (strcmp((*(pt + j)).name, a) == 0)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
							       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
					}
				};
				break;//��������ѯ
				case 3:
					system("cls");
					isr();
					break;
				default:
					printf("�������\n");
					system("cls");
					isr();
					break;
			}
		};
		break;//��ѯѧ���ɼ�
		case 2: {
			int j;
			printf("��ѡ���Ŀ��\n");
			printf("\t\t\t\t1.course1\t\t2.course2\n\t\t\t\t3.course3\t\t4.course4\n\t\t\t\t5.ȫ��\t\t\t6.������һ��\n");
			printf("������ѡ����Ŀ���֣�");
			scanf("%d", &j);
			switch (j) {
				case 1: {
					int h;
					printf("������������������������������������������������\n\n");
					printf("course%d��������У�\n", j);
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course1 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
				case 2: {
					int h;
					printf("������������������������������������������������\n");
					printf("course%d��������У�\n\n", j);
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course2 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
				case 3: {
					int h;
					printf("������������������������������������������������\n");
					printf("course%d��������У�\n\n", j);
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course3 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
				case 4: {
					int h;
					printf("������������������������������������������������\n");
					printf("course%d��������У�\n\n", j);
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course4 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
				case 5: {
					int h;
					printf("������������������������������������������������\n");
					printf("course1��������У�\n\n");
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course1 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
					printf("������������������������������������������������\n");
					printf("course2��������У�\n\n");
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course2 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
					printf("������������������������������������������������\n");
					printf("course3��������У�\n\n");
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course1 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
					printf("������������������������������������������������\n");
					printf("course4��������У�\n\n");
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course4 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
			}
		};//��ѯ��Ŀ������ѧ��
		break;
		case 3:
			system("cls");
			menu(pt);
			break;
		default:
			system("cls");
			printf("�������");
			isr();
			break;
	}
	printf("��ѯ��ϣ�");
	system("pause");
}

//���ļ��������ݸ�ֵ�����飬�ر��ļ������ؽṹ��ָ��
struct student *openclose() {
	struct student stu[N], *pt;
	int i;
	FILE *fp1;
	pt = stu;
	if ((fp1 = fopen("cp", "rb")) == NULL) {
		if ((fp = fopen("cp", "wb")) == NULL) {
			printf("�½������ļ�ʧ�ܣ�");
			menu();
			return 0;
		}
	} else {
		if ((fp = fopen("cp", "rb")) == NULL)
			printf("���ļ�����\n");
		fseek(fp, 0, 2);
		i = ftell(fp);
		i = i / 80;
		int j;
		for (j = 0; j < i; j++) {
			fseek(fp, 80 * j, 0);
			fread((pt + j), 80, 1, fp);
		}
		fclose(fp);
	}
	return pt;
}

//��ѯ�ṹ�����鳤��
int length() {
	int i = 0, j = 1;
	FILE *fp1;
	fp1 = fopen("cp", "rb");
	fseek(fp1, 0, 2);
	i = ftell(fp);
	fclose(fp1);
	i = i / 80;
	return i;
}

//���ѧ���ɼ�����ѡ��༶����ȫ��
void osr() {
	struct student  *pt;
	int i, m;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\tû��ѧ����Ϣ��\n");
		system("pause");
		return;
	}
	printf("\t\t\t\t1.���༶���\n\t\t\t\t2.ȫ�����\n\t\t\t\t3.�������˵�\n");
	printf("������ѡ�����Ŀ���ƣ�");
	scanf("%d", &m);
	switch (m) {
		case 1: {
			char temp[16];
			int j;
			printf("������������������������������������������������\n");
			printf("\n������ѡ��İ༶��");
			scanf("%s", temp);
			for (j = 0; j < i; j++) {
				if (strcmp((*(pt + j)).cla, temp) == 0) {
					printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
					       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
				}
			}
		};
		break;//���༶���
		case 2: {
			int j;
			for (j = 0; j < i; j++) {
				printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
				       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
			}
		};
		break;//ȫ�����
		case 3:
			system("cls");
			menu();
			break;
		default:
			printf("�������\n���������룡\n");
			system("cls");
			osr();
			break;
	}
	printf("������������������������������������������������\n");
	printf("�����ϣ�\n");
	system("pause");
}