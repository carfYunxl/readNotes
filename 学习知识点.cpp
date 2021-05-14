/*---------------1.Qframe---------------*/
QTextEdit *edit = new QTextEdit(this);
edit->setFrameStyle(5);
edit->setFrameShape(QFrame::VLine);
edit->setFrameShadow(QFrame::Plain);
edit->setLineWidth(1);

/*---------------2.打开软件，关闭软件淡入淡出效果---------------*/
**主要使用setWindowOpacity(p);
QTimer *timer2 = new QTimer(this);
    connect(timer2,&QTimer::timeout,[=](){      
        static double p = 0.0;
        if(p <= 1)
        {
            setWindowOpacity(p);
            p += 0.05;
        }
    });
    timer2->start(100);
	
if(event->buttons() == Qt::RightButton)
    {
        int ret = QMessageBox::information(this,"tips:","right can close the window,Yes to do that!",
                                 QMessageBox::Yes |
                                 QMessageBox::No,QMessageBox::Yes);
        if(ret == QMessageBox::Yes)
        {
            static double q = 1.0;
            while(q >= 0)
            {
                setWindowOpacity(q);
                q -= 0.05;
                Sleep(100);
            }
            this->close();
        }
/*---------------3.QWidget相关的类---------------*/
*************************************************************************************************************
**3.1 Basic Widget class

QCheckBox							Checkbox with a text label;

QComboBox							Combined button and popup list;

QCommandLinkButton					Vista style command link button;

QDateEdit							Widget for editing dates based on the QDateTimeEdit widget;

QDateTimeEdit						Widget for editing dates and times;

QDial								Rounded range control (like a speedometer or potentiometer);

QDoubleSpinBox						Spin box widget that takes doubles;

QFocusFrame							Focus frame which can be outside of a widget's normal paintable area;

QFontComboBox						Combobox that lets the user select a font family;

QLCDNumber							Displays a number with LCD-like digits;

QLabel								Text or image display;

QLineEdit							One-line text editor;

QMenu								Menu widget for use in menu bars, context menus, and other popup menus;

QProgressBar						Horizontal or vertical progress bar;

QPushButton							Command button;

QRadioButton						Radio button with a text label;

QScrollArea							Scrolling view onto another widget;

QScrollBar							Vertical or horizontal scroll bar;

QSizeGrip							Resize handle for resizing top-level windows;

QSlider								Vertical or horizontal slider;

QSpinBox							Spin box widget;

QTabBar								Tab bar, e.g. for use in tabbed dialogs;

QTabWidget							Stack of tabbed widgets;

QTimeEdit							Widget for editing times based on the QDateTimeEdit widget;

QToolBox							Column of tabbed widget items;

QToolButton							Quick-access button to commands or options, usually used inside a QToolBar;

QWidget								The base class of all user interface objects;
*************************************************************************************************************

**3.2 Advanced Widget Classes
QCalendarWidget						Monthly based calendar widget allowing the user to select a date

QColumnView							Model/view implementation of a column view

QDataWidgetMapper					Mapping between a section of a data model to widgets

QListView							List or icon view onto a model

QTableView							Default model/view implementation of a table view

QTreeView							Default model/view implementation of a tree view

QUndoView							Displays the contents of a QUndoStack
*************************************************************************************************************
**3.3 Abstract Widget Classes
QAbstractButton						The abstract base class of button widgets, providing functionality common to buttons

QAbstractScrollArea					Scrolling area with on-demand scroll bars

QAbstractSlider						Integer value within a range

QAbstractSpinBox					Spinbox and a line edit to display values

QDialog								The base class of dialog windows

QFrame								The base class of widgets that can have a frame
*************************************************************************************************************
**3.4 Organizer Widget Classes
QButtonGroup						Container to organize groups of button widgets

QGroupBox							Group box frame with a title

QSplitter							Implements a splitter widget

QSplitterHandle						Handle functionality for the splitter

QStackedWidget						Stack of widgets where only one widget is visible at a time

QTabWidget							Stack of tabbed widgets
*************************************************************************************************************
**3.5 Graphics View Classes
QAbstractGraphicsShapeItem			Common base for all path items

QGraphicsAnchor						Represents an anchor between two items in a QGraphicsAnchorLayout

QGraphicsAnchorLayout				Layout where one can anchor widgets together in Graphics View

QGraphicsEffect						The base class for all graphics effects

QGraphicsEllipseItem				Ellipse item that you can add to a QGraphicsScene

QGraphicsGridLayout					Grid layout for managing widgets in Graphics View

QGraphicsItem						The base class for all graphical items in a QGraphicsScene

QGraphicsItemGroup					Container that treats a group of items as a single item

QGraphicsLayout						The base class for all layouts in Graphics View

QGraphicsLayoutItem					Can be inherited to allow your custom items to be managed by layouts

QGraphicsLineItem					Line item that you can add to a QGraphicsScene

QGraphicsLinearLayout				Horizontal or vertical layout for managing widgets in Graphics View

QGraphicsObject						Base class for all graphics items that require signals, slots and properties

QGraphicsPathItem					Path item that you can add to a QGraphicsScene

QGraphicsPixmapItem					Pixmap item that you can add to a QGraphicsScene

QGraphicsPolygonItem				Polygon item that you can add to a QGraphicsScene

QGraphicsProxyWidget				Proxy layer for embedding a QWidget in a QGraphicsScene

QGraphicsRectItem					Rectangle item that you can add to a QGraphicsScene

QGraphicsScene						Surface for managing a large number of 2D graphical items

QGraphicsSceneContextMenuEvent		Context menu events in the graphics view framework

QGraphicsSceneDragDropEvent			Events for drag and drop in the graphics view framework

QGraphicsSceneEvent					Base class for all graphics view related events

QGraphicsSceneHelpEvent				Events when a tooltip is requested

QGraphicsSceneHoverEvent			Hover events in the graphics view framework

QGraphicsSceneMouseEvent			Mouse events in the graphics view framework

QGraphicsSceneMoveEvent				Events for widget moving in the graphics view framework

QGraphicsSceneResizeEvent			Events for widget resizing in the graphics view framework

QGraphicsSceneWheelEvent			Wheel events in the graphics view framework

QGraphicsSimpleTextItem				Simple text path item that you can add to a QGraphicsScene

QGraphicsSvgItem					QGraphicsItem that can be used to render the contents of SVG files

QGraphicsTextItem					Text item that you can add to a QGraphicsScene to display formatted text

QGraphicsTransform					Abstract base class for building advanced transformations on QGraphicsItems

QGraphicsView						Widget for displaying the contents of a QGraphicsScene

QGraphicsWidget						The base class for all widget items in a QGraphicsScene

QStyleOptionGraphicsItem			Used to describe the parameters needed to draw a QGraphicsItem
*************************************************************************************************************
**3.6 Model/View Classes
QAbstractItemDelegate				Used to display and edit data items from a model

QAbstractItemModel					The abstract interface for item model classes

QAbstractItemView					The basic functionality for item view classes

QAbstractListModel					Abstract model that can be subclassed to create one-dimensional list models

QAbstractProxyModel					Base class for proxy item models that can do sorting, filtering or other data processing tasks

QAbstractTableModel					Abstract model that can be subclassed to create table models

QColumnView							Model/view implementation of a column view

QConcatenateTablesProxyModel		Proxies multiple source models, concatenating their rows

QDataWidgetMapper					Mapping between a section of a data model to widgets

QFileSystemModel					Data model for the local filesystem

QHeaderView							Header row or header column for item views

QIdentityProxyModel					Proxies its source model unmodified

QItemDelegate						Display and editing facilities for data items from a model

QItemEditorCreator					Makes it possible to create item editor creator bases without subclassing QItemEditorCreatorBase

QItemEditorCreatorBase				Abstract base class that must be subclassed when implementing new item editor creators

QItemEditorFactory					Widgets for editing item data in views and delegates

QItemSelection						Manages information about selected items in a model

QItemSelectionModel					Keeps track of a view's selected items

QItemSelectionRange					Manages information about a range of selected items in a model

QListView							List or icon view onto a model

QListWidget							Item-based list widget

QListWidgetItem						Item for use with the QListWidget item view class

QModelIndex							Used to locate data in a data model

QModelRoleData						Holds a role and the data associated to that role

QModelRoleDataSpan					Span over QModelRoleData objects

QPersistentModelIndex				Used to locate data in a data model

QSortFilterProxyModel				Support for sorting and filtering data passed between another model and a view

QStandardItem						Item for use with the QStandardItemModel class

QStandardItemEditorCreator			The possibility to register widgets without having to subclass QItemEditorCreatorBase

QStandardItemModel					Generic model for storing custom data

QStringListModel					Model that supplies strings to views

QStyledItemDelegate					Display and editing facilities for data items from a model

QTableView							Default model/view implementation of a table view

QTableWidget						Item-based table view with a default model

QTableWidgetItem					Item for use with the QTableWidget class

QTableWidgetSelectionRange			Way to interact with selection in a model without using model indexes and a selection model

QTreeView							Default model/view implementation of a tree view

QTreeWidget							Tree view that uses a predefined tree model

QTreeWidgetItem						Item for use with the QTreeWidget convenience class

QTreeWidgetItemIterator				Way to iterate over the items in a QTreeWidget instance
*************************************************************************************************************
**3.7 Main Window and Related Classes
QDockWidget							Widget that can be docked inside a QMainWindow or floated as a top-level window on the desktop

QMainWindow							Main application window

QMdiArea							Area in which MDI windows are displayed

QMdiSubWindow						Subwindow class for QMdiArea

QMenu								Menu widget for use in menu bars, context menus, and other popup menus

QMenuBar							Horizontal menu bar

QSizeGrip							Resize handle for resizing top-level windows

QStatusBar							Horizontal bar suitable for presenting status information

QToolBar							Movable panel that contains a set of controls

QWidgetAction						Extends QAction by an interface for inserting custom widgets into action based containers, such as toolbars
*************************************************************************************************************
**3.8 Widget Appearance and Style-Related Classes
QColor								Colors based on RGB, HSV or CMYK values

QColorSpace							Color space abstraction

QColorTransform						Transformation between color spaces

QCommonStyle						Encapsulates the common Look and Feel of a GUI

QCursor								Mouse cursor with an arbitrary shape

QFont								Specifies a query for a font used for drawing text

QFontDatabase						Information about the fonts available in the underlying window system

QFontInfo							General information about fonts

QGraphicsAnchor						Represents an anchor between two items in a QGraphicsAnchorLayout

QGraphicsAnchorLayout				Layout where one can anchor widgets together in Graphics View

QPalette							Contains color groups for each widget state

QStyle								Abstract base class that encapsulates the look and feel of a GUI

QStyleFactory						Creates QStyle objects

QStyleHintReturn					Style hints that return more than basic data types

QStyleHintReturnMask				Style hints that return a QRegion

QStyleHintReturnVariant				Style hints that return a QVariant

QStyleOption						Stores the parameters used by QStyle functions

QStylePainter						Convenience class for drawing QStyle elements inside a widget
*************************************************************************************************************
**3.9 Layout Classes
QBoxLayout							Lines up child widgets horizontally or vertically

QButtonGroup						Container to organize groups of button widgets

QFormLayout							Manages forms of input widgets and their associated labels

QGraphicsAnchor						Represents an anchor between two items in a QGraphicsAnchorLayout

QGraphicsAnchorLayout				Layout where one can anchor widgets together in Graphics View

QGridLayout							Lays out widgets in a grid

QGroupBox							Group box frame with a title

QHBoxLayout							Lines up widgets horizontally

QLayout								The base class of geometry managers

QLayoutItem							Abstract item that a QLayout manipulates

QSizePolicy							Layout attribute describing horizontal and vertical resizing policy

QSpacerItem							Blank space in a layout

QStackedLayout						Stack of widgets where only one widget is visible at a time

QStackedWidget						Stack of widgets where only one widget is visible at a time

QVBoxLayout							Lines up widgets vertically

QWidgetItem							Layout item that represents a widget
