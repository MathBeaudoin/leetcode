echo "--- Creating a new directory for a C++ leetcode question ---"
echo "- What should be the name of the directory?"
read answer
mkdir $answer

touch $answer/Solution.cpp
cat 0-template-problem/Solution.cpp > $answer/Solution.cpp
echo ""
echo "New directory create with its associated file!"