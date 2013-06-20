//------------------------------DISPLAY FUNCTIONS----------------------------//

//display the menu with all the devices connected to the computer
void devicesMenu() {
  fill(0);
  int p = 0;
  //title of the menu
  text("Choose an available controller to use", width / 3, (height / 3) - SPACING);

  for (int i = 0; i < numberDevices; i++) {
    device = controll.getDevice(i);
    if ( device.getNumberOfSliders () > 4) {
      p++;
      text(device.getName(), width / 3, (height / 3) + SPACING * p);
      menu[i] = new textButton(device.getName(), width / 3, (height / 3) + SPACING * p);
      menu[i].show();
      if (menu[i].clicked()) {
        deviceN = i;
        picked = true;
        break;
      }
    }
  }
}

void HUD () {
  if (!stopped) {
    //get values from the controller
    instance();
  }
  //draw the graphs to the screen
  graphSect.show();
  clock.display(width * 9 / 10, height * 9 / 10);
}

void curves() {
  statesMenu.smallScreen();
  statesMenu.clicked();
  clock.display( width * 9 / 10, height * 9 / 10);
}

void menu() {
  statesMenu.fullScreen();
  statesMenu.clicked();
}
