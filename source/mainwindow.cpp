#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mymodel.h"
#include "headerCpp.h"
#include "pages.h"
#include "player.h"
#include "QHeaderView"




QMainWindow* thisP;
QVector<Player> players;
QVector<QString> emptyVec;
QVector<Page> pages;

QString menuLabels[] = {"Exit", "Select character", "Create character", "Edit name", "Change score"};
QVector<QString> menuOpts;

QString charSelectLabels[] = {"Player", "Level", "Score"};
QVector<QString> charSelectHeader;

MyModel myModel(nullptr, 0, 3);
int page;
int playerNum = 0;

void createPlayer(QVector<Player>& players) //creates an new Player object
{
    Player player;
    player.askName();
    players.push_back(player);
    playerNum++;
}

void init() //initialize
{

    page = 0;
    int arrSize = sizeof(menuLabels)/sizeof(QString); //create menu option vector
    for(int i = 0; i < arrSize; i++)
    {
        menuOpts.push_back(menuLabels[i]);
    }

    arrSize = sizeof(charSelectLabels)/sizeof(QString); //create menu option vector
    for(int i = 0; i < arrSize; i++)
    {
        charSelectHeader.push_back(charSelectLabels[i]);
    }

     // START Page constructions
    Page Exit("I see how it is.", emptyVec, emptyVec, emptyVec, 0, false, 1, emptyVec, false); //exit page
    Page Menu("Please pick one:", menuOpts, emptyVec, emptyVec, 1, false, 1, emptyVec, false); //menu
    Page CharSelect("Select a character:", emptyVec, emptyVec, emptyVec, 2, true, 3, charSelectHeader, false); // character select
    Page CharCreate("", emptyVec, emptyVec, emptyVec, 3, false, 1, emptyVec, true);                   // character create
    Page NameEdit("Enter your new name:", emptyVec, emptyVec, emptyVec, 4, false, 1, emptyVec, true);  // edit name
    Page ScoreAdd("How many points would you like to add?", emptyVec, emptyVec, emptyVec, 5, false, 1, emptyVec, true); //score adder


    pages.push_back(Menu); // 0
    pages.push_back(Exit); // 1
    pages.push_back(CharSelect); // 2
    pages.push_back(CharCreate); // 3
    pages.push_back(NameEdit); // 4
    pages.push_back(ScoreAdd); // 5

    // END page constructions

    createPlayer(players);


    character = 0;

}







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thisP = this;


    init();

/*
    MyModel myModel(nullptr, 3, 3);
    QTableView* tableView = new QTableView;
    tableView->setModel(&myModel);
    w.setCentralWidget(tableView);
    tableView->show();


*/


    playing = true;

  //  QObject::connect(ui->actionTest, &QAction::triggered, this,  &MainWindow::triggerAccept);

//while (playing)
//    {





  //      page = pages[page].doFunc();


//    }




/*
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->vLayout->layout());

    QWidget *window = new QWidget(this);

    window->setLayout(layout);

  //  setCentralWidget(qobject_cast<QWidget*>(ui->vLayout->layout()));
    setCentralWidget(window);

    QTableView* tableView = new QTableView(this);
    MyModel myModel(nullptr, 0, 3);

    cout << "Test4" << endl;
    //delete tableView;
    cout << "Test5" << endl;
    pages[page].display(myModel);
    tableView->setModel(&myModel);
    cout << "Test6" << endl;
    cout << tableView << endl;


    layout->addWidget(tableView);
   // tableView->show();

*/
 //   setCentralWidget(tableView);
  //  tableView->show();



  //  ui->tableView->setModel(&myModel);


    // addWidget(tableView);
}

void MainWindow::onTableClicked(QModelIndex index)
{
    cout << index.row() << ", " << index.column() << endl;
    page = pages[page].doFunc(index);
    tableDisplay(tableViewP);
}

void MainWindow::tableDisplay(QTableView* tableView)
{

   /* QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->vLayout->layout());
    QTableView* tableView = new QTableView(this);
    MyModel myModel(nullptr, 0, 3);

    cout << "Test4" << endl;
    //delete tableView;
    cout << "Test5" << endl;
    pages[page].display(myModel);
    tableView->setModel(&myModel);
    cout << "Test6" << endl;
    cout << tableView << endl;



    layout->addWidget(tableView);
    cout << "Test7" << endl;
    tableView->show();
    cout << "Test8" << endl;
    */

    if (page == 1)
    {
        QApplication::quit();
    }

    emit myModel.layoutAboutToBeChanged();
    pages[page].display(myModel);

    tableView->setModel(&myModel);




  //  QModelIndexList selection = tableView->selectionModel()->selectedIndexes();
   // this->drive_->recalculate(selection);


    emit myModel.dataChanged(myModel.topLeft, myModel.bottomRight, {Qt::DisplayRole});
    emit myModel.layoutChanged();

    tableView->verticalHeader()->show();

    if(pages[page].headers == emptyVec)
    {
        tableView->horizontalHeader()->hide();
    } else
    {
        tableView->horizontalHeader()->show();
    }

    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->resizeRowsToContents();
    statusBar()->showMessage("Playing as: " + players[character].getName());
    if(pages[page].input)
    {
        page = pages[page].doFunc(myModel.index(0, 0));
        tableDisplay(tableViewP);
    }

}

/*
void MainWindow::triggerAccept()
{
    tableDisplay(tableViewP);
    update();
}
*/
void MainWindow::setTableView(QTableView& tableView)
{
    tableViewP = &tableView;
    connect(tableViewP, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onTableClicked(QModelIndex)));
}


void MainWindow::on_actionTest_triggered()
{
    page = 0;
    tableDisplay(tableViewP);

}

MainWindow::~MainWindow()
{
    delete ui;
}





