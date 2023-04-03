#include <glut.h>

void drawSquare() {
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}

void translate(float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(x, y, z);
}

void rotate(float angle, float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(angle, x, y, z);
}

void scale(float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(x, y, z);
}

void display() {
    // Xóa màn hình
    glClear(GL_COLOR_BUFFER_BIT);
    // Vẽ hình vuông trước khi biến đổi
    glColor3f(1.0f, 1.0f, 1.0f);
    drawSquare();
    // Dịch chuyển hình vuông sang phải
    translate(0.5f, 0.0f, 0.0f);
    // Vẽ hình vuông sau khi dịch chuyển
    glColor3f(1.0f, 0.0f, 0.0f);
    drawSquare();
    // Xoay hình vuông 45 độ quanh trục z
    rotate(45.0f, 0.0f, 0.0f, 1.0f);
    // Vẽ hình vuông sau khi xoay
    glColor3f(0.0f, 1.0f, 0.0f);
    drawSquare();
    // Co giãn hình vuông theo chiều x và y
    scale(2.0f, 1.5f, 1.0f);
    // Vẽ hình vuông sau khi co giãn
    glColor3f(0.0f, 0.0f, 1.0f);
    drawSquare();
    // Swap buffers
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    // Khởi tạo Glut
    glutInit(&argc, argv);
    // Đặt chế độ hiển thị cho Glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    // Đặt kích thước cửa sổ đồ họa
    glutInitWindowSize(640, 480);
    // Tạo cửa sổ đồ họa
    glutCreateWindow("OpenGL");
    // Đăng ký hàm hiển thị
    glutDisplayFunc(display);
    // Vòng lặp hiển thị
    glutMainLoop();
    return 0;
}
