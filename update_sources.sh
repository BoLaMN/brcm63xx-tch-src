#!/bin/bash
REPO_ROOT="$1"
ARCHIVE_ROOT="$2"

######################################
echo -n "Cleaning up broadcom-bsp... "

rm -rf "$REPO_ROOT/extern/broadcom-bsp" && echo "done"
mkdir -p "$REPO_ROOT/extern/broadcom-bsp"

###############################
echo -n "Copying userspace... "

cp -rf "$ARCHIVE_ROOT/bcm_userspace" "$REPO_ROOT/extern/broadcom-bsp/bcm_userspace" && echo "done"
#cp -rf "$ARCHIVE_ROOT/bcm_userspace/broadcom_apps/shared" "$REPO_ROOT/extern/broadcom-bsp/shared"

####################################
echo -n "Copying kernel modules... "

cp -rf "$ARCHIVE_ROOT/kernel/broadcom_modules" "$REPO_ROOT/extern/broadcom-bsp/broadcom_modules" && echo "done"
#cp -rf "$ARCHIVE_ROOT/kernel/broadcom_modules/bcmdrivers" "$REPO_ROOT/extern/broadcom-bsp/bcmdrivers"

##########################
echo "Applying patches..."

pushd "$REPO_ROOT/extern"
patch -p1 < "$REPO_ROOT/extern.patch"
popd

##############################
echo -n "Repacking kernel... "

rm -rf "$REPO_ROOT/dl/linux-3.4.11"
cp -f "$REPO_ROOT/dl/linux-3.4.11.tar.xz" "$REPO_ROOT/dl/linux-3.4.11.tar.xz.old"
tar cJf "$REPO_ROOT/dl/linux-3.4.11.tar.xz" "$ARCHIVE_ROOT/kernel/broadcom_kernel/kernel/linux-3.4rt" && echo "done"
