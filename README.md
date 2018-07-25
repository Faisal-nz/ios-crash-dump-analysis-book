# iOS Crash Dump Analysis Book

The HTML version of the book, "iOS Crash Dump Analysis" is available at the link:
https://faisalmemon.github.io/ios-crash-dump-analysis-book/

The purpose of this repository is to provide the source code and other resources supporting the iOS crash dump analysis book.  The initial intention is to provide the book in two parts, the first part being an introduction, and the second part an advanced book.

## Why write this book?

When I look around at colleagues I notice that we all come to app programming from different career paths.  It seemed like everyone else found crash dump fixing burdensome apart from myself.
I came to app programming from the bottom upwards.  I started off as a device driver and kernel engineer and took subsequent jobs in the middleware layer and then lastly in the app layer.
This less trodden route has given me a perspective which I would like to share with other developers and engineers.

## It's already documented right?

1. There are lots of documents on the specifics of exploring crash dumps, but they exist in a knowledge bubble not connected to the normal app developer experience; they feel alien.  The knowledge is generally scattered around without a definitive guide.  I would like collect the information together into one place.

1. Software engineering concepts can be employed to avoid crashes, and to lessen the pain in finding and resolving them.  I would like shine a light on this aspect of engineering so you can improve your codebase proactively.

1. Step-by-step guides often seem to make large logical jumps to derive the answer to why an app crashed.  But crash dump analysis is just problem-solving in a specific domain.  There are systematic problem solving approaches that can be applied here.  I have found these helpful in my own work and want to share the insights more widely.

It's my opinion that when you put these three approaches together: software engineering, systematic problem solving, and crash dump exploration you end up with a powerful toolbox you can take with you to any iOS app project.
You will be able to spend less time fixing crashes, and more time writing valuable functionality.  That's something we all want!

# Project Details

## Directory Structure

Directory | Purpose
----------| -------
external | Downloaded resources
topics | Topic specific writing
source | Parent directory of compilable source code
markdown | Markdown files for the body text of the book
examples | Examples of crashes
automation | Not yet used
screenshots | Screenshots

## Branch Policy

The software configuration management plan (SCM plan) is very simple.
- All development is done on the master branch.
- When a version of the book is published a numbered release branch is made, e.g. `release/1.0`

## Authoring Methodology

I aim to follow a similar approach as http://rtalbert.org/how-i-wrote-my-book/ and Ben Watson at [Philosophical Geek](http://www.philosophicalgeek.com/2014/11/10/tips-for-writing-a-programming-book/)

- Write the content of the book in markdown
- Use pandoc to convert the markdown into MS Word format
- Use Calibre to convert MS Word into EPUB format
- Import the EPUB into iBooks author and Kindle KDP

From experiment I've found importing InDesign format files as a chapter in iBooks author does not work.  There seems to be a file version compatibility issue between pandoc and iBook Author.

## Supporting software

### Essential Software

You need:
- Brew Package manager
- Various Brew packages
- Latex packages
- Class dump
- Calibre

#### Brew Software

I used the Brew package manager on MacOS and used the Brew packages:

Brew Package | Purpose
--|--
`pandoc` | Document translator to get from .markdown format to other formats
`pandoc-citeproc` | Biliography Citation Helper for pandoc

#### Latex Support

Latex support appears not to be available directly in brew so I used the recommended [MacTex](https://www.tug.org/mactex/) and this was installed via a brew cask install
`brew cask install mactex`

#### Class Dump

For analysing binaries I used `class-dump`.  Whilst previously this was available from Brew, it seems now you have to directly download it.

[Download class-dump](http://stevenygard.com/projects/class-dump/)


#### Calibre Tool

I use the [Calibre](https://calibre-ebook.com/dist/osx) tool to convert MS Word documents into EPUB format files so I can then import them into Kindle Direct Publishing and iBooks Author.

I tried various combinations but the MS Word format works best as an input source for Calibre.  The output seen in iBook is impressive.  The output seen in KDP is faulty - it shows the blue color everywhere.  I need to fix that.

I've tried various "official" E-book tools but Calibre seems the best: doesn't crash, it's automatic, the default results look great.

### Recommended Software

Package | Purpose
--|--
Atom|Edits and understands markdown and can preview render it
BibDesk | Eases the definition of Citations for the Biliography

## Essential Mac Configuration

#### Screenshots

I have discovered the standard screenshot on Mac only does low resolution (screen resolution) images.  Print books need to have higher resolution.

I saw an answer at: https://apple.stackexchange.com/a/110206

I need to experiment in this area.  Maybe putting my screen in large scale mode will give me screenshots with effectively a higher ppi when shrunk down for print.

## Build System

The book is built using `buildBook.sh`

The build outputs are:

File | Purpose
--|--
`foo.html` | Intermediate used for GitHub Pages documentation
`foo.pdf` | For the Hard Copy Paper Edition
`foo.docx` | For further conversion into EPUB, and internally for spelling and grammar checking
`foo.epub` | For E-book readers (Apple and Amazon)
`docs/*` | Final destination for GitHub Pages documentation

The output are `foo.*` files locally for ease of inspection.  They are ignored by version control.

For github pages, the GitHub documentation facility, the HTML documentation and supporting resources is copied into the `docs` directory and then they are checked in (the branch is required to be master).

The build system also checks for uses of "you" - they should be "we" in all cases apart from the Introduction.

The main purpose of the `docx` version was I could not get a good quality E-book generated automatically from pandoc.  But going via Calibre sorts out the problem.

The reason why I am not using `docx` for the Paperback edition is because there is no filter that will allow me to convert embedded index references in the markdown into docx references.  Creating the index would then be a manual task.  For a 300 page book, that's one week of work!


# Ignore this section

I tried to install fonts to get a latex template working but keep hitting problems.  My original instructions were:

#### Font Support

For the document template I wanted to use I needed `sourcesanspro.sty` so
I downloaded [SourceSansPro.zip](http://mirrors.ctan.org/install/fonts/sourcesanspro.tds.zip)

-  `sudo cp -Rfp sourcesanspro/* /opt/local/share/texmf-texlive` to overlay the downloaded font into the existing system tree.
-  `sudo vi /opt/local/var/db/texmf/web2c/updmap.cfg` to append the line `Map SourceSansPro.map`
-  Update indexes `sudo mktexlsr`
-  Install the fonts with `sudo -H updmap-sys`

In fact I needed a collection of fonts and resources:

Resource|Location
--|--
SansPro | http://mirrors.ctan.org/install/fonts/sourcesanspro.tds.zip
Ly1 | http://mirrors.ctan.org/fonts/psfonts/ly1.zip
MWeights | http://mirrors.ctan.org/macros/latex/contrib/mweights.zip
