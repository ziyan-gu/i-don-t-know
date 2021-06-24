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
void menu();//菜单函数，调用其它函数
void rsg();//选择按班级或者学期录入学生成绩
void modify();//选择按班级或者学期修改学生信息
void del();//删除学生信息
void ssa();//统计学生成绩，求总分和平均分，并根据平均成绩进行排序
void isr();//可以查询单个学生成绩，查看每个科目不及格学生名单
void osr();//输出学生成绩，可选择班级，或全部
int length();//查询结构体数组长度
struct student *openclose();//打开文件，把数据赋值给数组，关闭文件，返回结构体指针
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
		printf("\t\t\t\t\t***欢迎进入学生成绩管理系统***\n");
		printf("---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\n");
		printf("请选择服务项目——\n\n");
		printf("\t\t\t1.录入学生成绩\t\t\t\t2.统计学生成绩\n");
		printf("\t\t\t3.查询学生成绩\t\t\t\t4.浏览学生成绩\n");
		printf("\t\t\t5.修改学生信息\t\t\t\t6.删除学生成绩\n");
		printf("\t\t\t7.退出信息系统\n\n");
		printf("---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t---\n");
		printf("请输入您选择的项目数字:");
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
				printf("正在退出中···\n");
				exit(0);
			default:
				system("cls");
				printf("\t\t\t\t\t输入错误！\n");
				menu();
		}
	}

}

//选择按班级或者学期录入学生成绩
void rsg() {
	struct student *pt;
	int i, m, j;
	char temp[16];
	pt = openclose();
	i = length();
	printf("\t\t\t\t1.按班级录入\n\t\t\t\t2.按学期录入\n\t\t\t\t3.返回主菜单\n");
	printf("————————————————————————\n");
	printf("请输入您选择的项目数字：");
	scanf("%d", &m);
	switch (m) {
		case 1: {
			printf("请输入录入班级名：");
			scanf("%s", temp);
			printf("————————————————————————\n");
			printf("请输入学生成绩信息：\n");
			printf("例：B20041613  顾守正  100  100  100  100  大一下");
			printf("（当输入数值全为0时终止输入）\n");
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
		break;//按班级录入
		case 2: {
			printf("请输入录入学期：");
			scanf("%s", temp);
			printf("————————————————————————\n");
			printf("请输入学生成绩信息：\n");
			printf("例：B20041613  顾守正  B200416 100  100  100  100");
			printf("（当输入数值全为0时终止输入）\n");
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
		break;//按学期录入
		case 3: {
			system("cls");
			menu();
			break;
		}
		break;
		default:
			system("cls");
			printf("\t\t\t\t\t输入错误\n");
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
		printf("录入成功！");
		system("pause");
	}
}

//选择按班级或者学期修改学生信息
void modify() {
	struct student *pt;
	char temp[16];
	int j, t, a, i, n;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\t没有学生信息！\n");
		system("pause");
		return;
	}
	printf("\t\t\t\t1.按班级修改\n\t\t\t\t2.按学期修改\n\t\t\t\t3.返回主菜单\n");
	printf("请输入项目数字：");
	scanf("%d", &n);
	switch (n) {
		case 1: {
			printf("请输入班级：");
			scanf("%s", temp);
			for (j = 0; j < i; j++) {
				if (strcmp((*(pt + j)).cla, temp) == 0) {
					printf("%d.", j);
					printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
					       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
				}
			}
			printf("请输入修改人数：");
			scanf("%d", &t);
			printf("例：B20041613 顾守正 100 100 100 100 大一下\n");
			printf("————————————————————————\n");
			for (j = 0; j < t; j++) {
				printf("请选择修改学生序号：");
				scanf("%d", &a);
				printf("请输入修改学生信息：\n");
				scanf("%s %s %d %d %d %d %s", (*(pt + a)).num, (*(pt + a)).name, &(*(pt + a)).course1, &(*(pt + a)).course2,
				      &(*(pt + a)).course3, &(*(pt + a)).course4, (*(pt + a)).term);
			}
		};
		break;//按班级修改
		case 2: {
			printf("请输入学期：");
			scanf("%s", temp);
			for (j = 0; j < i; j++) {
				if (strcmp((*(pt + j)).term, temp) == 0) {
					printf("%d.", j);
					printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
					       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
				}
			}
			printf("请输入修改人数：");
			scanf("%d", &t);
			printf("例：B20041613 顾守正 B200416 100 100 100 100\n");
			printf("————————————————————————\n");
			for (j = 0; j < t; j++) {
				printf("请选择修改学生序号：");
				scanf("%d", &a);
				printf("请输入修改学生信息：\n");
				scanf("%s %s %s %d %d %d %d", (*(pt + a)).num, (*(pt + a)).name, (*(pt + a)).cla, &(*(pt + a)).course1,
				      &(*(pt + a)).course2,
				      &(*(pt + a)).course3, &(*(pt + a)).course4);
			}
		};
		break;//按学期修改
		case 3: {
			menu();
		};
		break;//返回主菜单
		default: {
			printf("输出错误！");
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
		printf("修改成功！\n");
		system("pause");
	}
}

//删除学生信息
void del() {
	struct student *pt, data[N];
	char temp[16];
	int i, n = -1, j;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\t没有学生信息！\n");
		system("pause");
		return;
	}
	printf("请输入要删除的学生学号：");
	scanf("%s", temp);
	printf("————————————————————————\n");
	for (j = 0; j < i; j++) {
		if (strcmp((*(pt + j)).num, temp) == 0) {
			printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
			       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
			n = j;
			break;
		}
	}
	if (n == -1) {
		printf("没有该学生信息！");
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
	printf("删除成功！");
	system("pause");
}

//按班级统计学生成绩，求总分和平均分，并根据平均成绩进行排序
void ssa() {
	struct student *pt, ht[1];
	int i, j, n, k;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\t没有学生信息！\n");
		system("pause");
		return;
	}
	printf("\t\t\t\t1.求总分和平均分并排序\n\t\t\t\t2.返回主菜单\n请输入选择项目数字：");
	scanf("%d", &n);
	printf("————————————————————————\n");
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
		printf("排序成功！\n");
		system("pause");
	}
}

//可以查询单个学生成绩，查看每个科目不及格学生名单
void isr() {
	struct student *pt;
	int i;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\t没有学生信息！\n");
		system("pause");
		return;
	}
	printf("\t\t\t\t1.查询学生成绩\n\t\t\t\t2.查询科目不及格学生\n\t\t\t\t3.返回主菜单\n");
	int m;
	printf("请输入选择项目数字：");
	scanf("%d", &m);
	printf("————————————————————————\n");
	switch (m) {
		case 1: {
			printf("\t\t\t\t1.按学号查询\n\t\t\t\t2.按姓名查询\n\t\t\t\t3.返回上一级\n");
			printf("请输入选择项目数字：");
			scanf("%d", &m);
			switch (m) {
				case 1: {
					char a[16];
					int j;
					printf("请输入学号：");
					scanf("%s", a);
					for (j = 0; j < i; j++) {
						if (strcmp((*(pt + j)).num, a) == 0)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
							       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
					}
				};
				break;//按学号查询
				case 2: {
					char a[16];
					int j;
					printf("请输入姓名：");
					scanf("%s", a);
					for (j = 0; j < i; j++) {
						if (strcmp((*(pt + j)).name, a) == 0)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
							       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
					}
				};
				break;//按姓名查询
				case 3:
					system("cls");
					isr();
					break;
				default:
					printf("输入错误！\n");
					system("cls");
					isr();
					break;
			}
		};
		break;//查询学生成绩
		case 2: {
			int j;
			printf("请选择科目：\n");
			printf("\t\t\t\t1.course1\t\t2.course2\n\t\t\t\t3.course3\t\t4.course4\n\t\t\t\t5.全部\t\t\t6.返回上一级\n");
			printf("请输入选择项目数字：");
			scanf("%d", &j);
			switch (j) {
				case 1: {
					int h;
					printf("————————————————————————\n\n");
					printf("course%d不及格的有：\n", j);
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course1 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
				case 2: {
					int h;
					printf("————————————————————————\n");
					printf("course%d不及格的有：\n\n", j);
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course2 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
				case 3: {
					int h;
					printf("————————————————————————\n");
					printf("course%d不及格的有：\n\n", j);
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course3 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
				case 4: {
					int h;
					printf("————————————————————————\n");
					printf("course%d不及格的有：\n\n", j);
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course4 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
				case 5: {
					int h;
					printf("————————————————————————\n");
					printf("course1不及格的有：\n\n");
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course1 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
					printf("————————————————————————\n");
					printf("course2不及格的有：\n\n");
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course2 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
					printf("————————————————————————\n");
					printf("course3不及格的有：\n\n");
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course1 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
					printf("————————————————————————\n");
					printf("course4不及格的有：\n\n");
					for (h = 0; h < i; h++) {
						if ((*(pt + h)).course4 < 60)
							printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + h)).num, (*(pt + h)).name, (*(pt + h)).cla,
							       (*(pt + h)).course1, (*(pt + h)).course2, (*(pt + h)).course3, (*(pt + h)).course4, (*(pt + h)).term);
					}
				};
				break;
			}
		};//查询科目不及格学生
		break;
		case 3:
			system("cls");
			menu(pt);
			break;
		default:
			system("cls");
			printf("输入错误！");
			isr();
			break;
	}
	printf("查询完毕！");
	system("pause");
}

//打开文件，把数据赋值给数组，关闭文件，返回结构体指针
struct student *openclose() {
	struct student stu[N], *pt;
	int i;
	FILE *fp1;
	pt = stu;
	if ((fp1 = fopen("cp", "rb")) == NULL) {
		if ((fp = fopen("cp", "wb")) == NULL) {
			printf("新建数据文件失败！");
			menu();
			return 0;
		}
	} else {
		if ((fp = fopen("cp", "rb")) == NULL)
			printf("打开文件出错\n");
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

//查询结构体数组长度
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

//输出学生成绩，可选择班级，或全部
void osr() {
	struct student  *pt;
	int i, m;
	pt = openclose();
	i = length();
	if (i == 0) {
		printf("\t\t\t\t没有学生信息！\n");
		system("pause");
		return;
	}
	printf("\t\t\t\t1.按班级输出\n\t\t\t\t2.全部输出\n\t\t\t\t3.返回主菜单\n");
	printf("请输入选择的项目名称：");
	scanf("%d", &m);
	switch (m) {
		case 1: {
			char temp[16];
			int j;
			printf("————————————————————————\n");
			printf("\n请输入选择的班级：");
			scanf("%s", temp);
			for (j = 0; j < i; j++) {
				if (strcmp((*(pt + j)).cla, temp) == 0) {
					printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
					       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
				}
			}
		};
		break;//按班级输出
		case 2: {
			int j;
			for (j = 0; j < i; j++) {
				printf("%s\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%s\n", (*(pt + j)).num, (*(pt + j)).name, (*(pt + j)).cla,
				       (*(pt + j)).course1, (*(pt + j)).course2, (*(pt + j)).course3, (*(pt + j)).course4, (*(pt + j)).term);
			}
		};
		break;//全部输出
		case 3:
			system("cls");
			menu();
			break;
		default:
			printf("输入错误！\n请重新输入！\n");
			system("cls");
			osr();
			break;
	}
	printf("————————————————————————\n");
	printf("输出完毕！\n");
	system("pause");
}