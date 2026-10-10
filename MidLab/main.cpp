#include <GL/glut.h>

// Global offsets to center the character on the grid
int offsetX = 8;
int offsetY = 2;

// Function to draw a single pixel block
void p(int x, int y, float* c) {
    glColor3fv(c);
    glBegin(GL_QUADS);
        glVertex2i(x + offsetX, y + offsetY);
        glVertex2i(x + offsetX + 1, y + offsetY);
        glVertex2i(x + offsetX + 1, y + offsetY + 1);
        glVertex2i(x + offsetX, y + offsetY + 1);
    glEnd();
}

// Helper to draw a horizontal row of pixels
void row(int x1, int x2, int y, float* c) {
    for(int x = x1; x <= x2; x++) p(x, y, c);
}

// Helper to draw a vertical column of pixels
void col(int x, int y1, int y2, float* c) {
    for(int y = y1; y <= y2; y++) p(x, y, c);
}

void display() {
    // Background color matching the image
    glClearColor(0.53f, 0.67f, 0.84f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Color Palette
    float black[] = {0.11f, 0.11f, 0.11f};
    float skin[]  = {0.99f, 0.85f, 0.77f};
    float white[] = {1.00f, 1.00f, 1.00f};
    float jeans[] = {0.05f, 0.41f, 0.73f};
    float cuff[]  = {0.46f, 0.69f, 0.89f};
    float belt[]  = {0.31f, 0.34f, 0.36f};

    // --- LEGS & BOOTS ---
    // Boots
    row(0, 2, 0, black); row(5, 7, 0, black);
    row(1, 2, 1, black); row(5, 6, 1, black);
    // Light Blue Cuffs
    row(1, 2, 2, cuff);  row(5, 6, 2, cuff);
    // Jeans
    for(int y = 3; y <= 9; y++) {
        row(1, 2, y, jeans);
        row(5, 6, y, jeans);
    }

    // --- WAIST & HANDS ---
    row(1, 6, 10, belt);    // Belt spans across
    col(0, 8, 9, skin);     // Left hand
    col(7, 8, 9, skin);     // Right hand

    // --- TORSO (Jacket, Shirt, Zipper, Arms) ---
    col(0, 10, 16, black);  // Left sleeve
    col(7, 10, 16, black);  // Right sleeve

    col(3, 11, 12, belt);   // Dark grey zipper line

    // White V-Neck Shirt (Asymmetrical stepped pattern)
    p(3, 13, white);
    row(3, 4, 14, white);
    row(3, 4, 15, white);
    row(2, 4, 16, white);

    // Black Jacket Body
    col(1, 11, 17, black);  // Left inner lapel
    col(2, 11, 15, black);  // Left outer chest
    p(2, 17, black);        // Left collar point
    col(4, 11, 13, black);  // Right inner chest
    col(5, 11, 17, black);  // Right outer chest
    col(6, 11, 17, black);  // Right shoulder/collar

    // --- HEAD & FACE ---
    // Skin (Neck, Face, Nose)
    row(3, 4, 17, skin);    // Neck
    row(2, 4, 18, skin);    // Chin/Jaw
    row(1, 4, 19, skin);    // Nose area sticking out
    row(1, 3, 20, skin);    // Mid face
    p(4, 21, skin);         // Forehead gap
    row(3, 4, 22, skin);    // Upper forehead

    // Hair & Sunglasses (Black)
    col(5, 18, 25, black);  // Back of head/hair base
    col(6, 18, 23, black);  // Back of head/hair edge

    p(0, 20, black);        // Sunglasses front rim drop
    p(4, 20, black);        // Sideburn
    row(0, 3, 21, black);   // Sunglasses top bar
    row(1, 2, 22, black);   // Hair overhang above glasses

    // Pompadour Top
    row(2, 4, 23, black);
    row(2, 4, 24, black);
    row(2, 4, 25, black);

    glFlush();
}

void init() {
    // Set up a 24x30 pixel grid projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 24, 0, 30);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 750); // Ratio matching the 24x30 grid
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pixel Art Greaser (Exact Replica)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
