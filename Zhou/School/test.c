#include "lib.h"

LLNode *gNodePtr;

void initRegSystem() {
	gNodePtr = (LLNode *)malloc(sizeof(LLNode));
	memset(gNodePtr, 0, sizeof(LLNode));
}

LLNode *findUser(const char *id) {
	for (LLNode *it = gNodePtr; it != NULL; it = it->next) {
		if (!strcmp(it->id, id)) {
			return it;
		}
	}
	return NULL;
}

void userRegister() {
	LLNode *node = (LLNode *)malloc(sizeof(LLNode));
	node->next = NULL;

	printf("请输入一个用户ID\n");
	scanf("%s", node->id);
	printf("请设置密码\n");
	scanf("%s", node->pass);

	if (findUser(node->id) != NULL) {
		printf("用户已经被注册!\n");
		free(node);
		return;
	}

	LLNode *it;
	for (it = gNodePtr; it->next != NULL; it = it->next)
		;
	it->next = node;
	printf("注册成功\n");
}

bool userLogin() {
	char idbuf[20];
	char passbuf[20];

	printf("请输入用户名\n");
	scanf("%s", idbuf);
	printf("请输入密码\n");
	scanf("%s", passbuf);

	LLNode *user = findUser(idbuf);
	if (user == NULL || strcmp(user->pass, passbuf)) {
		printf("用户不存在或密码错误!\n");
		return false;
	}
	printf("登录成功\n");
	return true;
}

