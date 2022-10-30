
#include "Application.h"





int main()
{
	printf("Choose 1-3\n");
	int choice = 0;
	scanf_s("%d", &choice);
	Application app = Application();
	app.printVersionInfo();
	app.run(choice);

}
